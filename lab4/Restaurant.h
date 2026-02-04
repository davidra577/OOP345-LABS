// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace sdds
{
    class Restaurant
    {
        size_t storedIndex;
        Reservation* reservs;

    public:
        Restaurant();
        ~Restaurant();
        Restaurant(const Reservation* reservations[], size_t cnt);
        size_t size() const;

        Restaurant(const Restaurant&);           
        Restaurant& operator=(const Restaurant&); 
        Restaurant(Restaurant&&);                 
        Restaurant& operator=(Restaurant&&);     

        void display(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& out, const Restaurant& restaurant);
    };  
}

#endif