#include <cpp_python.h>
using namespace cpp_python;

#include <iostream>
#include <cassert>
#include <vector>
#include <ranges>

int main() {
  auto func = [](int x) { return 1.; };
  static_assert(cpp_python_concepts::MinimumFunc <int, decltype(func)>);
  static_assert(std::is_same_v< typename std::remove_reference_t < std::vector <int> > :: value_type, int>);
  static_assert(std::is_same_v < int&, decltype(*std::ranges::begin(std::declval < std::add_lvalue_reference_t < std::remove_reference_t < std::vector <int> > > > ())) >);
  static_assert(std::is_same_v < int&, decltype(*std::ranges::begin(std::declval < std::add_lvalue_reference_t < std::remove_reference_t < std::vector <int>& > > > ())) >);
  static_assert(std::is_same_v < int&, decltype(*std::ranges::begin(std::declval < std::add_lvalue_reference_t < std::remove_reference_t < std::vector <int>&& > > > ())) >);
}