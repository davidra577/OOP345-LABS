/**********************************************************
 * Name: Karanpreet Singh
 * Student ID: 144886173
 * Workshop4: part 2
 * Seneca email: ks23@myseneca.ca
 * Section: NEEL
 **********************************************************/

 /*I have done all the coding by myself and only copied the code
  that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
    class Reservation
    {
    protected:
        string res_id;
        string res_name;
        string res_email;
        int res_people;
        int res_day;
        int res_hour;

    public:
        Reservation();
        string removeSpaces(std::string str);
        Reservation(const string& res);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
    };
} // namespace sdds

#endif