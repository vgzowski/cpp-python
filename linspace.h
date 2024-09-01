#pragma once
#include <iostream>

#include <type_traits>
#include <iterator>

namespace cpp_python_concepts {
	template <typename T>
	concept NumericNonConst = std::is_arithmetic_v<T> &&
                          !std::is_pointer_v<T> &&
                          !std::is_reference_v<T> &&
                          !std::is_const_v<T>;
}

namespace cpp_python {
	template <typename T>
	class linspace_iterator {
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::input_iterator_tag;

		linspace_iterator(T start, T jump) : position_(start), jump_(jump) {}

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
			return position_ < other.position_;
		}
	private:
		T position_, jump_;
	};

	template <typename T>
	class linspace_const_iterator {
	public:
		using value_type = T;
		using reference = const T&;
		using pointer = const T*;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::input_iterator_tag;

		linspace_const_iterator(T start, T jump) : position_(start), jump_(jump) {}

		reference operator * () {
			return position_;
		}
		linspace_const_iterator & operator ++ () {
			position_ += jump_;
			return *this;
		}
    linspace_const_iterator operator ++ (int) {
			auto copy = *this;
			++(*this);
			return copy;
    }

		bool operator == (const linspace_const_iterator & other) const {
			return position_ == other.position_;
		}
		bool operator != (const linspace_const_iterator & other) const {
			return position_ < other.position_;
		}
	private:
		T position_, jump_;
	};

	template <cpp_python_concepts::NumericNonConst T>
	class linspace {
	public:
		using iterator = linspace_iterator <T>;
		using const_iterator = linspace_const_iterator <T>;

		linspace(T start, T finish, T jump) :
			begin_(iterator(start, jump)), end_(iterator(finish, jump)),
			cbegin_(const_iterator(start, jump)), cend_(const_iterator(finish, jump)) {
				static_assert(std::sentinel_for < iterator, iterator >);
				static_assert(std::sentinel_for < const_iterator, const_iterator >);
				static_assert(std::forward_iterator<iterator>);
				static_assert(std::forward_iterator<const_iterator>);
			}

		iterator begin() { return begin_; }
		iterator end() { return end_; }

		const_iterator begin() const { return cbegin_; }
		const_iterator end() const { return cend_; }
	private:
		iterator begin_;
		iterator end_;
		const_iterator cbegin_;
		const_iterator cend_;
	};
}
