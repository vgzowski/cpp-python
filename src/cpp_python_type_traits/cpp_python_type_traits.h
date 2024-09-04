#pragma once

namespace cpp_python_type_traits {
	template <typename T, bool isConst>
	struct container_iterator {};
	template <typename T>
	struct container_iterator <T, false> { typedef typename T::iterator iterator_type; };
	template <typename T>
	struct container_iterator <T, true> { typedef typename T::const_iterator iterator_type; };


	template <typename T>
	struct original { typedef std::remove_reference_t <T> type; };
	template <typename T>
	using original_t = typename original <T> :: type;


	template <typename T>
	using container_iterator_t = typename container_iterator < original_t <T>, std::is_const_v < original_t <T> > > :: iterator_type;
}