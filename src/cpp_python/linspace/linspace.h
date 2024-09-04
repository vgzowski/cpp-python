#pragma once

#include <cpp_python_concepts/cpp_python_concepts.h>

namespace cpp_python {
	template <typename T>
	class linspace_iterator {
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::input_iterator_tag;

    linspace_iterator() : position_(0), start_(0), jump_(0) {}
		linspace_iterator(T start, T jump) : position_(start), start_(start), jump_(jump) {}

		reference operator * () {
			return position_;
		}
		linspace_iterator & operator ++ () {
			position_ += jump_;
			return *this;
		}
    linspace_iterator operator ++ (int) {
			auto copy = *this;
			++(*this);
			return copy;
    }

		bool operator == (const linspace_iterator & other) const {
			return position_ == other.position_;
		}
		bool operator != (const linspace_iterator & other) const {
      if (start_ < other.start_) {
        return position_ < other.position_;
      }
      else {
        return position_ > other.position_;
      }
		}
	private:
		T position_, start_, jump_;
	};

	template <cpp_python_concepts::NumericNonConst T>
	class linspace {
	public:
		using iterator = linspace_iterator <T>;

		linspace(T start, T finish, T jump) :
			begin_(iterator(start, jump)), end_(iterator(finish, jump)) {}

		iterator begin() { return begin_; }
		iterator end() { return end_; }
	private:
		iterator begin_;
		iterator end_;
	};
}