// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds
{
    class Reservation
    {
    protected:
        std::string reservID;
        std::string reservName;
        std::string reservEmail;
        size_t reservPeople;
        size_t reservDay;
        size_t reservHour;

    public:
        Reservation();
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
}
#endif