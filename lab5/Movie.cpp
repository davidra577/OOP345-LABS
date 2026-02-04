// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include "Movie.h"
#include <iomanip>
#include <string>

namespace sdds
{
    Movie::Movie()
    {
        m_title = "\0";
        m_year = 0;
        m_description = "\0";
    }

    const std::string& Movie::title() const
    {
        return m_title;
    }

    Movie::Movie(const std::string& strMovie)
    {
        size_t start = 0;
        size_t end = strMovie.find(',');
        m_title = strMovie.substr(start, end);
        removeSpace(m_title);
        start = end + 1;
        end = strMovie.find(',', start);
        m_year = stoi(strMovie.substr(start, end - start));

        start = end + 1;
        m_description = strMovie.substr(start);
        removeSpace(m_description);
    }

    void Movie::removeSpace(std::string& str) const
    {
        size_t i = 0u;
        for (i = 0u; i < str.length() && str[i] == ' '; i++){}
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; i--){}
        str = str.substr(0, i);
    }

    Movie::~Movie() {};

    std::ostream& operator<<(std::ostream& out, const Movie& movie)
    {
        out << std::right << std::setw(40) << movie.m_title << " | ";
        out << std::setw(4) << movie.m_year << " | ";
        out << movie.m_description << std::endl;
        return out;
    }
} 
