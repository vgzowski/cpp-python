#pragma once

#include <ranges>
#include <linspace/linspace.h>

namespace cpp_python {
	template <std::ranges::range Container>
	inline decltype(auto) enumerate(Container&& container) {
    return zip(linspace(0, -1, 1), std::forward <Container> (container));
	}
}
