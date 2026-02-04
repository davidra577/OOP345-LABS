// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 3 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 6th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template<unsigned int N, typename T >
	class SetSummable : public Set<N, T> {
		T collection[N];
		size_t ele = 0;
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (unsigned int i = 0; i < this->size(); i++) {
				accumulator += this->get(i);
			}
			return accumulator;
		}

	};
}
#endif