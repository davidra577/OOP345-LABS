// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 3 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 6th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace sdds {

	template <typename V, typename K>
	class Pair {

		K keys;
		V values;

	public:
		Pair():keys{0}, values{0} {}
		
		Pair(const K& key, const V& value)
		{
			keys = key;
			values = value;
		}
		
		const K& key() const 
		{
			return keys;
		}

		const V& value() const 
		{
			return values;
		}

		virtual void display(std::ostream& os) const 
		{
			os << keys << " : " << values << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
		{
			pair.display(os);
			return os;
		}
	};

}
#endif
