// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
        const Reservation** reserv;
        size_t index;

    public:
        ConfirmationSender();
        ~ConfirmationSender();
        ConfirmationSender(const ConfirmationSender&);           
        ConfirmationSender& operator=(const ConfirmationSender&); 
        ConfirmationSender(ConfirmationSender&&);                 
        ConfirmationSender& operator=(ConfirmationSender&&);      
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        void display(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& out, const ConfirmationSender& cs);
    };

    

} 

#endif