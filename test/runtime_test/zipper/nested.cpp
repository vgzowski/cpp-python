#include <cpp_python.h>
using namespace cpp_python;

#include <iostream>
#include <vector>

int main() {
  std::vector <int> a{1, 2, 3, 7, 8};
  std::vector <int> b{10, 20, 30, 40};
  std::vector <int> c{50, 60, 70};

  for (auto x : zip(zip(a, b), c)) {
    std::cout << x.first.first << " " << x.first.second << " " << x.second << std::endl;
  }
}