// Reservation.h
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Sept. 30, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef sdds_Reservation_h
#define sdds_Reservation_h

#include <iostream>

namespace sdds
{
    class Reservation
    {
        std::string id_;
        std::string name_;
        std::string email_;
        int partySize_;
        int day_;
        int hour_;

      public:
        Reservation();
        Reservation(const std::string &m_res);
        std::string removeSpaces(std::string str);
        void display(std::ostream& os) const;
        ~Reservation();
        friend std::ostream& operator<<(std::ostream& out, const Reservation& reservation);
    };


} // namespace sdds

#endif