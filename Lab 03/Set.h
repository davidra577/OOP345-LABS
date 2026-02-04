// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 3 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 6th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SET_H
#define SET_H
#include <iostream>

namespace sdds {

	template<unsigned int N, typename T >
	class Set {
		T collection[N];
		size_t ele = 0;

	public:

		size_t size() const 
		{
			return ele;
		}

		const T& get(size_t idx) const
		{

			return collection[idx];
		}

		void operator+=(const T& item) 
		{
			if (ele < N) {
				collection[ele] = item;
				ele++;
			}
		}

	};

}

#endif