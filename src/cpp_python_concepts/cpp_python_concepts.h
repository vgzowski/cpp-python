#pragma once

#include <ranges>
#include <cpp_python_type_traits/cpp_python_type_traits.h>

namespace cpp_python_concepts {
	template <typename T>
	concept BiContainer = std::ranges::range < std::remove_const_t < cpp_python_type_traits::original_t <T> > > && std::is_base_of_v <
		std::bidirectional_iterator_tag,
		typename std::iterator_traits < cpp_python_type_traits::container_iterator_t <T> > :: iterator_category
	>;

	template <typename T>
	concept FwContainer = std::ranges::range < std::remove_const_t < cpp_python_type_traits::original_t <T> > > && std::is_base_of_v <
		std::forward_iterator_tag,
		typename std::iterator_traits < cpp_python_type_traits::container_iterator_t <T> > :: iterator_category
	>;

  template <typename T>
	concept InpContainer = std::ranges::range < std::remove_const_t < cpp_python_type_traits::original_t <T> > > && std::is_base_of_v <
		std::input_iterator_tag,
		typename std::iterator_traits < cpp_python_type_traits::container_iterator_t <T> > :: iterator_category
	>;
}

namespace cpp_python_concepts {
	template <typename T>
	concept NumericNonConst = std::is_arithmetic_v<T> &&
                          !std::is_pointer_v<T> &&
                          !std::is_reference_v<T> &&
                          !std::is_const_v<T>;
}

namespace cpp_python_concepts {
	template <typename T>
	concept LessThanComparable = requires(T a, T b) {
		{ a < b } -> std::convertible_to <bool>;
	};

	template <typename Value, typename Func>
	concept MinimumFunc = requires(Value v, Func f) {
		{ f(v) } -> LessThanComparable;
	};

	template <typename Container, typename Func>
	concept MinimumFuncCont = MinimumFunc < typename std::remove_reference_t <Container> :: value_type, Func >;
}