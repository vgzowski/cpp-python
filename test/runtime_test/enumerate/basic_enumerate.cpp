#include <cpp_python.h>
using namespace cpp_python;

#include <iostream>
#include <vector>
#include <set>

int main() {
  std::vector <int> a{10, 20, 30};
  std::set <int> s{5, 2, 1, 100324, -1, 3};

  for (auto x : enumerate(a)) {
    std::cout << x.first << " " << x.second << std::endl;
  }
  std::cout << std::endl;
  for (const auto& x : enumerate(s)) {
    std::cout << x.first << " " << x.second << std::endl;
  }
}