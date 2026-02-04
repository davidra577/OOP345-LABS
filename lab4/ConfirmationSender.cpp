// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include "ConfirmationSender.h"
#include <iostream>

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        reserv = nullptr;
        index = 0;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] reserv;
        reserv = nullptr;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) : reserv{nullptr}
    {
        *this = cs;
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) 
    {
        if (this != &cs) {
            delete[] this->reserv;
            this->index = cs.index;
            reserv = new const Reservation * [index];
            for (size_t i = 0; i < index; i++)
            {
                reserv[i] = cs.reserv[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) : reserv {nullptr}
    {
        *this = std::move(cs);
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) 
    {
        if (this != &cs) {
            delete[] reserv;
            reserv = cs.reserv;
            index = cs.index;
            cs.reserv = nullptr;
            cs.index = 0;
        }
        return *this;
    }


    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool found = false;
        for (size_t i = 0; i < index; i++ && !found)
        {
            if (reserv[i] == &res) {
                found = true;
            }
        }
        if (found == false)
        {
            if (index == 0) {
                index++;
                reserv = new const Reservation * [index];
                reserv[0] = &res;
            }
            else {
                const Reservation** temp2 = new const Reservation * [index];
                for (size_t i = 0; i < index; i++)
                {
                    temp2[i] = reserv[i];
                }
                index++;
                delete[] reserv;
                reserv = new const Reservation * [index];
                for (size_t i = 0; i < index -1;i++)
                {
                    reserv[i] = temp2[i];
                }
                delete[] temp2;
                temp2 = nullptr;
                reserv[index - 1] = &res;
                
            }

        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        for (size_t i = 0; i < index; i++)
        {
            if (reserv[i] == &res) {
                reserv[i] = nullptr;
                const Reservation** tmp = new const Reservation* [index - 1];
                for (size_t i = 0, j = 0; i < index; i++, j++)
                {
                    if (reserv[i] != nullptr) {
                        tmp[j] = reserv[i];
                    }
                    else {
                        j--;
                    }
                }
                delete[] reserv;
                index--;
                reserv = new const Reservation * [index];
                for (size_t i = 0; i < index; i++)
                {
                    reserv[i] = tmp[i];
                }
                delete[] tmp;
                tmp = nullptr;
            }
        }
        return *this;
    }

    void ConfirmationSender::display(std::ostream& os) const
    {
        std::cout << "--------------------------\n";
        std::cout << "Confirmations to Send\n";
        std::cout << "--------------------------\n";
        if (index == 0) {
            std::cout << "There are no confirmations to send!\n";
            std::cout << "--------------------------\n";
        }
        else {
            for (size_t i = 0; i < index; i++)
            {
                os << (*reserv[i]);
            }
            std::cout << "--------------------------\n";
        }
    }

    std::ostream& operator<<(std::ostream& out, const ConfirmationSender& cs)
    {
        cs.display(out);
        return out;
    }
} 
