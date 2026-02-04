// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef sdds_SpellChecker_h
#define sdds_SpellChecker_h
#include <iostream>

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};

}
#endif