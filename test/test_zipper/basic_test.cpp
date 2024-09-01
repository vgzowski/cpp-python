#include "../../zipper.h"
using namespace cpp_python;
using namespace cpp_python_type_traits;
using namespace zipper;

#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <set>
#include <string>
#include <list>
#include <forward_list>

template <typename A, typename B>
std::ostream & operator << (std::ostream & out, const std::pair <A, B> &p) {
	out << "(" << p.first << " " << p.second << ")";
	return out;
}

template <typename A>
void func(A&& vec) {
	std::vector <int> a{4, 5, 6};
	for (auto x : zip(a, std::forward<A>(vec))) {
		std::cout << x << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	static_assert(
		std::is_same_v <
			const int &,
			decltype( (*std::declval<zip_iterator<std::vector<int>, const std::vector<int>&>>()).second )
		>
	);
	static_assert(
		std::is_same_v <
			int &,
			decltype( (*std::declval<zip_iterator<std::vector<int>, const std::vector<int>&>>()).first )
		>
	);

	std::vector <int> vec_int_3{1, 2, 3};
	std::vector <int> vec_int_5{5, 6, 7, 8, 9};
	const std::vector <int> vec_int_4{1, 3, 6, 7};

	std::vector <std::string> vec_string_3{"vgzowki", "github", "cool"};
	std::vector <std::string> vec_string_2{"a", "c"};
	std::vector <std::string> vec_string_5{"a", "aa", "aaa", "aaaa", "aaaa"};

	std::set <int> set_int_2{1, 2};
	std::set <int> set_int_5{10, 20, 30, 50, 40};
	std::set <std::string> set_string{"string1set", "string2set", "string3set"};


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


	func(vec_int_3);
	// func(std::move(vec_int_3)); - Works but will destroy vec_int_3
	func(vec_int_4);
	// func(std::move(vec_int_4)); - Works but will destroy vec_int_4

	for (auto x : zip(std::vector<int>{1,2,3,4}, vec_int_4)) {
		std::cout << x << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;


	for (auto x : zip(vec_int_3, vec_int_5)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;
	for (auto x : zip(vec_int_5, vec_int_4)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(vec_int_5, vec_string_5)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;
	for (auto x : zip(vec_string_3, vec_int_4)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(set_int_2, vec_string_3)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;
	for (auto x : zip(set_int_5, vec_string_3)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(set_int_5, set_int_2)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	std::cout << "-------------------------------------" << std::endl;







	for (auto x : zip(set_int_5, std::vector<char>{'a', 'b', 'c', 'd', 'e'})) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(std::vector<int>{1,2,3,4}, vec_string_5)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(std::move(vec_int_5), vec_string_3)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	for (auto x : zip(std::move(vec_int_5), std::move(set_int_2))) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	std::cout << "-------------------------------------" << std::endl;









	std::forward_list <int> fwd_list_int_3{1, 2, 3};
	std::list <int> list_int_3{10, 20, 30};

	for (auto x : zip(vec_int_3, list_int_3)) {
		std::cout << x << std::endl;
	}
	std::cout << "----------------" << std::endl;

	std::cout << "Changing" << std::endl;
	for (auto x : zip(vec_int_3, vec_int_4)) {
		std::cout << x << std::endl;
		x.first = 0;
	}
	std::cout << "Changed" << std::endl;
	for (auto x : zip(vec_int_3, vec_int_4)) {
		std::cout << x << std::endl;
	}
	std::cout << "---" << std::endl;

// CE - forward list is not bidirectional
//	for (auto x : zip(vec_int_3, fwd_list_int_3)) {
//		std::cout << x << std::endl;
//	}
//	std::cout << "----------------" << std::endl;



// CE - x.second is const int & (vec_int_4 is const, so modifying is not allowed)
//	std::cout << "Changing" << std::endl;
//	for (auto x : zip(vec_int_3, vec_int_4)) {
//		std::cout << x << std::endl;
//		x.second = 0;
//	}


	if (true) {
		srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());

		std::vector <int> A(1000, rand());
		std::vector <int> B(1000, rand());
		int iters = (int)1e6;
		int div = iters / 5;

		auto start = std::chrono::high_resolution_clock::now();	
		for (int iterations = 0; iterations < iters; ++iterations) {
			std::vector < std::pair <int, int> > copy(1000);
			for (int i = 0; i < 1000; ++i) {
				copy[i] = {A[i], B[i]};
			}
			long long sum = 0;
			for (int i = 0; i < 1000; ++i) {
				sum += copy[i].first * 1ll * copy[i].second;
			}
			if ((iterations + 1) % div == 0) std::cout << sum << std::endl;
		}
		auto end1 = std::chrono::high_resolution_clock::now();
		for (int iterations = 0; iterations < iters; ++iterations) {
			long long sum = 0;
			for (int i = 0; i < 1000; ++i) {
				sum += A[i] * 1ll * B[i];
			}
			if ((iterations + 1) % div == 0) std::cout << sum << std::endl;
		}
		auto end2 = std::chrono::high_resolution_clock::now();
		for (int iterations = 0; iterations < iters; ++iterations) {
			long long sum = 0;
			for (auto [a, b] : zip(A, B)) {
				sum += a * 1ll * b;
			}
			if ((iterations + 1) % div == 0) std::cout << sum << std::endl;
		}
		auto end3 = std::chrono::high_resolution_clock::now();
		std::cout << "Copy:\t\t\t" << std::chrono::duration<double>(end1 - start).count() << std::endl;
		std::cout << "Iterating for:\t\t" << std::chrono::duration<double>(end2 - end1).count() << std::endl;
		std::cout << "ZIP:\t\t\t" << std::chrono::duration<double>(end3 - end2).count() << std::endl;
	}
}
