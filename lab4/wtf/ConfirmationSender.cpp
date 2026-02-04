// ConfirmationSender.cpp
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Oct. 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"
#include <iostream>

namespace sdds
{
    ConfirmationSender::ConfirmationSender()
    {
        reservationArr_ = nullptr;
        stored_ = 0;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender &cs) // Copy Constructor
    {
        *this = cs;
    }

    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &cs) // Copy operator
    {
        if (this != &cs)
        {
            delete[] reservationArr_;
            stored_ = cs.stored_;

            reservationArr_ = new const Reservation *[stored_];
            for (int i = 0; i < stored_; i++)
            {
                reservationArr_[i] = cs.reservationArr_[i];
            }
        }

        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &&cs) // Move constructor
    {
        *this = std::move(cs);
    }

    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&cs) // Move operator
    {
        if (this != &cs)
        {
            reservationArr_ = cs.reservationArr_;
            stored_ = cs.stored_;
            cs.reservationArr_ = nullptr;
            cs.stored_ = 0;
        }

        return *this;
    }

    ConfirmationSender::~ConfirmationSender()
    {
        delete[] reservationArr_;
        reservationArr_ = nullptr;
    }

    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &res)
    {
        bool isIn = false;

        if (stored_ > 0)
        {
            for (int i = 0; i < stored_; i++) // Search if already in array
            {
                if (reservationArr_[i] == &res)
                {
                    isIn = true;
                }
            }
        }

        if (isIn == false)
        {
            if (stored_ == 0)
            {
                reservationArr_ = new const Reservation *[stored_];
            }
            else // means there is existing data in array
            {
                const Reservation **temp = new const Reservation *[stored_];
                temp = reservationArr_;
                reservationArr_ = new const Reservation *[stored_];
                reservationArr_ = temp;
            }

            reservationArr_[stored_] = &res;
            stored_++;
        }

        return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res)
    {
        bool isIn = false;
        int pos = -1;

        for (int i = 0; i < stored_; i++) // Search if already in array
        {
            if (reservationArr_[i] == &res)
            {
                isIn = true;
                pos = i;
            }
        }

        if (isIn && pos > -1)
        {
            reservationArr_[pos] = nullptr;
            const Reservation **temp = new const Reservation *[stored_]; // create a new temp array
            temp = reservationArr_;                                      // copy array over to temp
            for (int i = pos; i < stored_; i++)                          // shift the array over in temp
            {
                temp[i] = temp[i + 1];
            }
            stored_--;
            reservationArr_ = new const Reservation *[stored_]; // create a smaller array
            for (int i = 0; i < stored_; i++)                   // store back original data with 1 missing, into smaller array
            {
                reservationArr_[i] = temp[i];
            }
        }

        return *this;
    }

    void ConfirmationSender::display(std::ostream &os) const
    {
        if (stored_ == 0)
        {
            std::cout << "--------------------------\n";
            std::cout << "Confirmations to Send\n";
            std::cout << "--------------------------\n";
            std::cout << "There are no confirmations to send!\n";
            std::cout << "--------------------------\n";
        }
        else
        {
            std::cout << "--------------------------\n";
            std::cout << "Confirmations to Send\n";
            std::cout << "--------------------------\n";
            for (int i = 0; i < stored_; i++)
            {
                (*reservationArr_[i]).display(os);
            }
            std::cout << "--------------------------\n";
        }
    }

    std::ostream &operator<<(std::ostream &out, const ConfirmationSender &cs)
    {
        cs.display(out);

        return out;
    }
} // namespace sdds
