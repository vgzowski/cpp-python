#pragma once

#include "linspace.h"
#include "zipper.h"
#include <iterator>
#include <ranges>

namespace cpp_python {
	template <std::ranges::range Container>
	inline decltype(auto) enumerate(Container&& container) {
		static_assert(std::ranges::range <Container>);
		static_assert(cpp_python_concepts::NumericNonConst <int>);
		static_assert(cpp_python_concepts::FwContainer <Container>);
		static_assert(std::is_base_of_v <
			std::input_iterator_tag,
			typename std::iterator_traits < cpp_python_type_traits::container_iterator_t < linspace <int> > > :: iterator_category
		>);
		static_assert(std::ranges::range <linspace <int>>);
//		static_assert(cpp_python_concepts::FwContainer <linspace<int>>);
		return 0;
//		return zip(linspace(0, -1, 1), std::forward <Container> (container));
	}
}
