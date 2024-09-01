#include "../../linspace.h"
#include <iostream>
using namespace cpp_python;

int main() {
	for (auto x : linspace(1, 5, 1)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : linspace(1, 5, 2)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : linspace(1, 5, 4)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (auto x : linspace(1, -15, -2)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : linspace(1, -15, -3)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (auto x : linspace(1.0, 3.4, 0.4)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	auto Z = linspace(0, 10, 1);
	for (auto x : Z) std::cout << x << " ";
	std::cout << std::endl;
	for (auto x : Z) std::cout << x << " ";
	std::cout << std::endl;
}
