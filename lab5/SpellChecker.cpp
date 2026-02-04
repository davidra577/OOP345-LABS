// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include "SpellChecker.h"
#include <iomanip>
#include <string>
#include <fstream>
namespace sdds
{
	const int SIZE = 6;
	static int count[SIZE]{ 0,0,0,0,0,0 };
	SpellChecker::SpellChecker()
	{
		*m_badWords = "\0";
		*m_goodWords = "\0";
	}

	SpellChecker::SpellChecker(const char* filename)
	{
		size_t  n = sizeof(m_badWords) / sizeof(m_badWords[0]);
		std::ifstream file(filename);
		if (file.is_open() == false)
		{
			throw ("Bad file name!");
		}
		for (size_t i = 0u; i < n; ++i)
		{
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		int n = sizeof(m_badWords) / sizeof(m_badWords[0]);
		int start = 0;

		for (int i = 0; i < n; i++)
		{
			do {
				start = (int)text.find(m_badWords[i]);
				if (start >= 0)
				{
					text.replace(start, m_badWords[i].length(), m_goodWords[i]);
					count[i] = count[i] + 1;
				}
			} while (start != -1);
		}
	}

	
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < SIZE; i++)
		{
			out.width(15);
			out << std::right;
			out << m_badWords[i];		
			out	<< ": " << count[i] << " replacements\n";

		}
	}
	
} 