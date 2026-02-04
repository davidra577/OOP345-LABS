// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef sdds_Movie_h
#define sdds_Movie_h
#include <iostream>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		~Movie();
		void removeSpace(std::string& str) const;
		friend std::ostream& operator<<(std::ostream& out, const Movie& movie);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_description);
			spellChecker(m_title);
		}
	};
}
#endif