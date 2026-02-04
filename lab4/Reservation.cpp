// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include <iomanip>
#include "Reservation.h"

namespace sdds
{
    Reservation::Reservation()
    {
        reservID = "";
        reservName = "";
        reservEmail = "";
        reservPeople = 0;
        reservDay = 0;
        reservHour = 0;
    }

    Reservation::Reservation(const std::string& res)
    {
        std::string str = res, id, name, email, people, day, hour;
 
        id = str.substr(0, str.find(':'));

        str.erase(0, str.find(':') + 1);
        name = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        email = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        people = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        day = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        hour = str.substr(0, str.find(','));

        id.erase(id.find_last_not_of(' ') +1);

        name.erase(name.find_last_not_of(' ') + 1);

        email.erase(0, email.find_first_not_of(' '));
        email.erase(email.find_last_not_of(' ') + 1);
        

        reservID = id;
        reservName = name;
        reservEmail = email;
        reservPeople = stoi(people);
        reservDay = stoi(day);
        reservHour = stoi(hour);
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& res)
    {
        os << "Reservation ";
        os << std::setw(10) << std::right << res.reservID << ": ";
        os << std::setw(20) << std::right << res.reservName << "  ";
        os << std::setw(24) << std::left << "<" + res.reservEmail + ">";
            
        if (6 <= res.reservHour && res.reservHour <= 9)
        {
            os << "Breakfast";
        }
        else if (11 <= res.reservHour && res.reservHour <= 15)
        {
            os << "Lunch";
        }
        else if (17 <= res.reservHour && res.reservHour <= 21)
        {
            os << "Dinner";
        }
        else
        {
            os << "Drinks";
        }
        os << " on day " << res.reservDay << " @ " << res.reservHour << ":00"
            << " for " << res.reservPeople;
        if (res.reservPeople == 1) {
            os << " person." << std::endl;
        }
        else {
            os << " people." << std::endl;
        }

        return os;
    }
    
} 
