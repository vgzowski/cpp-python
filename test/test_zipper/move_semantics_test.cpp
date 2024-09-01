#include <iostream>
#include <vector>

#include "../../zipper.h"
using namespace cpp_python;

// An iterable struct printing all of its ctors(), dtors() etc.

struct debug_struct {
	debug_struct() { std::cout << "ctor()" << std::endl; }
	~debug_struct() { std::cout << "~dtor()" << std::endl; }

	debug_struct(const debug_struct &) { std::cout << "copy ctor()" << std::endl; }
	debug_struct(debug_struct&&) { std::cout << "move ctor()" << std::endl; }

	debug_struct & operator = (const debug_struct &) { std::cout << "copy assign()" << std::endl; return *this; }
	debug_struct & operator = (debug_struct&&) { std::cout << "move assign()" << std::endl; return *this; }

	using iterator = std::vector <int>::const_iterator;
	iterator begin() const { return vec.begin(); }
	iterator end() const { return vec.end(); }
	const std::vector <int> vec = {1, 2, 3, 4, 5};
};

int main() {
	std::string skip(50, '-');
	{
		debug_struct a;
		debug_struct b;
		for (auto x : zip(a, b)) {
			std::cout << x.first << " " << x.second << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "Should be nothing beside 2 ctors and 2 dtors" << std::endl;
	std::cout << skip << std::endl;

	{
		debug_struct a;
		for (auto x : zip(a, debug_struct())) {
			std::cout << x.first << " " << x.second << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "Should be nothing beside 2 ctors, 1 move constructor, 2 dtors" << std::endl;
	std::cout << skip << std::endl;

	{
		debug_struct a;
		debug_struct b;
		for (auto x : zip(a, std::move(b))) {
			std::cout << x.first << " " << x.second << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "Should be nothing beside 2 ctors, 1 move constructor, 2 dtors" << std::endl;
	std::cout << skip << std::endl;
}
