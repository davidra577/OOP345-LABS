// ConfirmationSender.h
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Oct. 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_ConfirmationSender_h
#define sdds_ConfirmationSender_h

#include <iostream>
#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
        const Reservation** reservationArr_;
        int stored_;

    public:
        ConfirmationSender();
        ConfirmationSender(const ConfirmationSender&);            // Copy Constructor
        ConfirmationSender& operator=(const ConfirmationSender&); // Copy operator
        ConfirmationSender(ConfirmationSender&&);                 // Move constructor
        ConfirmationSender& operator=(ConfirmationSender&&);      // Move operator
        ~ConfirmationSender();
        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        void display(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& out, const ConfirmationSender& cs);

} // namespace sdds

#endif