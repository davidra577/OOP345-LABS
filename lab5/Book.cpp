// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include "Book.h"
#include <iomanip>
#include <string>

namespace sdds
{
    Book::Book()
    {
        m_author = "\0";
        m_title = "\0";
        m_country = "\0";
        m_year = 0;
        m_price = 0;
        m_description = "\0";
    }

    const std::string& Book::title() const
    {
        return m_title;
    }

    const std::string& Book::country() const
    {
        return m_country;
    }

    const size_t& Book::year() const
    {
        return m_year;
    }

    double& Book::price()
    {
        return m_price;
    }

    Book::Book(const std::string& strBook)
    {
        size_t start = 0;
        size_t end = strBook.find(',');
        m_author = strBook.substr(start, end);

        start = end + 1;
        end = strBook.find(',', start);
        m_title = strBook.substr(start, end - start);
        removeSpace(m_title);
        start = end + 1;
        end = strBook.find(',', start);
        m_country = strBook.substr(start, end - start);
        removeSpace(m_country);
        start = end + 1;
        end = strBook.find(',', start);
        m_price = stod(strBook.substr(start, end - start));
        start = end + 1;
        end = strBook.find(',', start);
        m_year = stoi(strBook.substr(start, end - start));
        start = end + 1;
        m_description = strBook.substr(start);
        removeSpace(m_description);
    }

    void Book::removeSpace(std::string& str) const
    {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; i++)
        {}
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; i--)
        {}
        str = str.substr(0, i);
    }

    Book::~Book() 
    {}

    std::ostream& operator<<(std::ostream& out, const Book& book)
    {
        out << std::right << std::setw(20) << book.m_author << " | ";
        out << std::right << std::setw(22) << book.m_title << " | ";
        out << std::right << std::setw(5) << book.m_country << " | ";
        out << std::setw(4) << book.m_year << " | ";
        out << std::right << std::setw(6) << std::setprecision(2) << std::fixed << book.m_price << " | ";
        out << book.m_description << std::endl;

        return out;
    }
} 
