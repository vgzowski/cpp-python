#pragma once

#include <ranges>
#include "enumerate.h"

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

namespace cpp_python {
	template <typename Func, std::ranges::range Container>
		requires cpp_python_concepts::MinimumFuncCont <Container, Func>
	inline decltype(auto) iterator_min(Container&& container, Func&& func) {
		auto first = std::ranges::begin(container);
		auto last = std::ranges::end(container);

		if (first == last) {
			return last;
		}

		auto result = func(*first);
		auto result_iterator = first;

		for (++first; first != last; ++first) {
			auto current = func(*first);
			if (current < result) {
				result = current;
				result_iterator = first;
			}
		}
		return result_iterator;
	}
}

namespace cpp_python {
	template <typename Func, std::ranges::range Container>
		requires cpp_python_concepts::MinimumFuncCont <Container, Func>
	inline decltype(auto) iterator_max(Container&& container, Func&& func) {
		auto first = std::ranges::begin(container);
		auto last = std::ranges::end(container);

		if (first == last) {
			return last;
		}

		auto result = func(*first);
		auto result_iterator = first;

		for (++first; first != last; ++first) {
			auto current = func(*first);
			if (!(current < result)) {
				result = current;
				result_iterator = first;
			}
		}
		return result_iterator;
	}
}

namespace cpp_python {
	template <typename Func, std::ranges::range Container>
		requires cpp_python_concepts::MinimumFuncCont <Container, Func>
	inline decltype(auto) index_value_min(Container&& container, Func&& func) {
		auto enumerate_container = enumerate(std::forward <Container> (container));
		return std::pair<int,int>(0,0);
		/*
		auto result = iterator_min(enumerate_container, [func = std::forward <Func> (func)](const auto &x) { return func(x.second); });
		if (result == std::ranges::end(enumerate_container)) {
			throw std::runtime_error("index_value_min() invoked on an empty sequence");
		}

		return *result;
		*/
	}

	template <typename Func, std::ranges::range Container>
		requires cpp_python_concepts::MinimumFuncCont <Container, Func>
	inline decltype(auto) index_value_max(Container&& container, Func&& func) {
		auto enumerate_container = enumerate(std::forward <Container> (container));
		auto result = iterator_max(enumerate_container, [func = std::forward <Func> (func)](const auto &x) { return func(x.second); });

		if (result == std::ranges::end(enumerate_container)) {
			throw std::runtime_error("index_value_min() invoked on an empty sequence");
		}

		return *result;
	}
}
