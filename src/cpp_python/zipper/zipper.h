#pragma once

#include <cpp_python_concepts/cpp_python_concepts.h>

namespace cpp_python {
  namespace zipper {
    template <cpp_python_concepts::InpContainer C1, cpp_python_concepts::InpContainer C2>
    class zip_iterator {
    private:
      typedef cpp_python_type_traits::container_iterator_t <C1> iter1_;
      typedef cpp_python_type_traits::container_iterator_t <C2> iter2_;
    public:
      using pointer = std::pair <iter1_, iter2_>;
      using value_type = std::pair < typename iter1_::value_type, typename iter2_::value_type >;
      using reference = std::pair < typename iter1_::reference, typename iter2_::reference >;
      using difference_type = typename iter1_::difference_type;
      using iterator_category = std::bidirectional_iterator_tag;

      zip_iterator() {
        ptr_ = std::make_pair(iter1_(), iter2_());
      }
      zip_iterator(const iter1_ &first, const iter2_ &second) {
        ptr_ = std::make_pair(first, second);
      }

      zip_iterator & operator ++ () {
        ++ptr_.first;
        ++ptr_.second;
        return *this;
      }
      zip_iterator operator ++ (int) {
        auto copy = *this;
        ++(*this);
        return copy;
      }

      reference operator * () {
        return { *ptr_.first, *ptr_.second };
      }
      pointer operator -> () {
        return ptr_;
      }

      bool operator == (const zip_iterator &other) const {
        return ptr_.first == other.ptr_.first && ptr_.second == other.ptr_.second;
      }
      bool operator != (const zip_iterator &other) const {
        return ptr_.first != other.ptr_.first && ptr_.second != other.ptr_.second;
      }
    private:
      pointer ptr_;
    };

    template <
      typename Container1,
      typename Container2
    >
    class zipper {
    public:
      using iterator = zip_iterator <Container1, Container2>;
      zipper(Container1&& c1, Container2&& c2) :
        ref_or_copy_c1(std::forward <Container1> (c1)),
        ref_or_copy_c2(std::forward <Container2> (c2)),

        begin_(ref_or_copy_c1.begin(), ref_or_copy_c2.begin()),
        end_(ref_or_copy_c1.end(), ref_or_copy_c2.end()) {}

      inline iterator begin() { return begin_; }
      inline iterator end() { return end_; }
    private:
      Container1 ref_or_copy_c1;
      Container2 ref_or_copy_c2;

      iterator begin_;
      iterator end_;
    };
  }

  template <typename C1, typename C2>
  zipper::zipper <C1, C2> zip(C1&& c1, C2&& c2) {
    return zipper::zipper <C1, C2> (std::forward <C1> (c1), std::forward <C2> (c2));
  }
}