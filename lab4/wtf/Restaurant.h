// Restaurant.h
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Oct. 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_Restaurant_h
#define sdds_Restaurant_h

#include "Reservation.h"
#include <iostream>

namespace sdds
{
    class Restaurant
    {
        size_t storedResv_;
        Reservation *reservation_;

      public:
        Restaurant();
        Restaurant(const Restaurant &);            // Copy Constructor
        Restaurant &operator=(const Restaurant &); // Copy operator
        Restaurant(Restaurant &&);                 // Move constructor
        Restaurant &operator=(Restaurant &&);      // Move operator
        Restaurant(const Reservation *reservations[], size_t cnt);
        ~Restaurant();
        void display(std::ostream &os) const;
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& out, const Restaurant& restaurant);
    };

    
} // namespace sdds

#endif