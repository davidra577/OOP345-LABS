// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef sdds_Book_h
#define sdds_Book_h
#include <iostream>

namespace sdds
{
	class Book
	{
	private:
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		~Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		void removeSpace(std::string& str) const;
		friend std::ostream& operator<<(std::ostream& out, const Book& book);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_description);
		}
	};



} // namespace sdds

#endif