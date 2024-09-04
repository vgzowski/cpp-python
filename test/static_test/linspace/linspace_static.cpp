#include <cpp_python.h>
#include <ranges>

int main() {
  static_assert(std::ranges::range < cpp_python::linspace <int> >);
}