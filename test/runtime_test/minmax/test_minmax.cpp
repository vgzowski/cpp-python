#include <cpp_python.h>
using namespace cpp_python;

#include <iostream>
#include <cassert>
#include <vector>
#include <ranges>

int main() {
	// {
	// 	std::vector <int> v{11, 12, 13, 14};
	// 	auto func = [](int x) { return ((double)x - 12.3) * ((double)x - 12.3) - 15; };

	// 	static_assert(std::is_same_v <int, std::vector<int>::value_type>);
	// 	static_assert(cpp_python_concepts::MinimumFunc < std::vector <int>::value_type, decltype(func) >);

	// 	auto position = *iterator_min(v, func);
	// 	std::cout << position << std::endl;
	// }
	// {
	// 	std::vector <int> v{};
	// 	auto func = [](int x) { return ((double)x - 12.3) * ((double)x - 12.3) - 15; };

	// 	auto position = iterator_min(v, func);
	// 	assert(position == v.end());
	// }
	{
		std::vector <int> v{11, 12, 13, 14};
		auto func = [](int x) { return ((double)x - 12.3) * ((double)x - 12.3) - 15; };

		std::cout << "Reference:" << std::endl;
		for (auto x : v) {
			std::cout << func(x) << " ";
		}
		std::cout << std::endl;

    // static_assert(cpp_python_concepts::MinimumFuncCont<std::vector<int>, decltype(func)>);

		auto [ind_mn, value_mn] = index_value_min(v, func);
		auto [ind_mx, value_mx] = index_value_max(v, func);
		std::cout << "At " << ind_mn << " " << value_mn << " " << func(value_mn) << std::endl;
		std::cout << "At " << ind_mx << " " << value_mx << " " << func(value_mx) << std::endl;
		std::cout << std::endl;
	}
}
