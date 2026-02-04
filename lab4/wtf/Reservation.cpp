// Reservation.cpp
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Sept. 30, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Reservation.h"
#include <iomanip>
#include <string>
#include <algorithm>

namespace sdds
{
    Reservation::Reservation()
    {
        id_ = "";
        name_ = "";
        email_ = "";
        partySize_ = 0;
        day_ = 0;
        hour_ = 0;
    }

    std::string Reservation::removeSpaces(std::string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());

        return str;
    }

    Reservation::Reservation(const std::string &m_res)
    {
        std::string str;
        std::string::size_type start;
        std::string::size_type end;

        str = removeSpaces(m_res);
        id_ = str.substr(0, 7);
        start = str.find(':') + 1;
        end = str.find(',');
        name_ = str.substr(start, end - start);
        str.erase(0, end + 1);
        for (int i = 0; i < 4; i++)
        {
            end = str.find(',') + 1;

            if (i == 0)
            {
                email_ = str.substr(0, end - 1);
            }
            else if (i == 1)
            {
                partySize_ = std::stoi(str.substr(0, end - 1));
            }
            else if (i == 2)
            {
                day_ = std::stoi(str.substr(0, end - 1));
            }
            else if (i == 3)
            {
                hour_ = std::stoi(str);
            }
            str.erase(0, end);
        }
    }

    Reservation::~Reservation() {}

    void Reservation::display(std::ostream &os) const
    {
        std::cout << "Reservation " << id_ << ": "
                  << std::setw(10) << std::right << name_ << "  "
                  << std::setw(20) << std::left << "<" + email_ + ">"
                  << "    ";
        if (6 <= hour_ && hour_ <= 9)
        {
            std::cout << "Breakfast";
        }
        else if (11 <= hour_ && hour_ <= 15)
        {
            std::cout << "Lunch";
        }
        else if (17 <= hour_ && hour_ <= 21)
        {
            std::cout << "Dinner";
        }
        else
        {
            std::cout << "Drinks";
        }
        std::cout << " on day " << day_ << " @ " << hour_ << ":00"
                  << " for " << partySize_ << " people." << std::endl;
    }

    std::ostream &operator<<(std::ostream &out, const Reservation &res)
    {
        res.display(out);

        return out;
    }
} // namespace sdds
