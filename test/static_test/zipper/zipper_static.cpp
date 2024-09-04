#include <cpp_python.h>

using namespace cpp_python;
using namespace cpp_python_type_traits;

#include <vector>
#include <ranges>
#include <iostream>

int main() {
  static_assert(
		std::is_same_v <
			const int &,
			decltype( (*std::declval<zipper::zip_iterator<std::vector<int>, const std::vector<int>&>>()).second )
		>
	);
	static_assert(
		std::is_same_v <
			int &,
			decltype( (*std::declval<zipper::zip_iterator<std::vector<int>, const std::vector<int>&>>()).first )
		>
	);

	static_assert(std::is_same_v < original_t < std::vector <int> >, std::vector <int> >);
	static_assert(std::is_same_v < original_t < std::vector <int> & >, std::vector <int> >);
	static_assert(std::is_same_v < original_t < std::vector <int> && >, std::vector <int> >);
	static_assert(std::is_same_v < original_t < const std::vector <int> >, const std::vector <int> >);
	static_assert(std::is_same_v < original_t < const std::vector <int> & >, const std::vector <int> >);

	static_assert(std::is_same_v < container_iterator_t < std::vector <int> >, std::vector<int>::iterator >);
	static_assert(std::is_same_v < container_iterator_t < std::vector <int> & >, std::vector<int>::iterator >);
	static_assert(std::is_same_v < container_iterator_t < std::vector <int> && >, std::vector<int>::iterator >);

	static_assert(std::is_same_v < container_iterator_t < const std::vector <int> >, std::vector<int>::const_iterator >);
	static_assert(std::is_same_v < container_iterator_t < const std::vector <int> & >, std::vector<int>::const_iterator >);

  static_assert(std::ranges::range < zipper::zipper < std::vector <int>, std::vector <int> > >);
}