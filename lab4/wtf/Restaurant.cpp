// Restaurant.cpp
// Name: Roger Yu
// Seneca Student ID: 104102181
// Seneca email: ryu31@myseneca.ca
// Date of completion: Oct. 7, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Restaurant.h"
#include <iostream>

namespace sdds
{
    Restaurant::Restaurant()
    {
        reservation_ = nullptr;
        storedResv_ = 0;
    }

    Restaurant::Restaurant(const Restaurant &res) // Copy Constructor
    {
        *this = res;
    }

    Restaurant &Restaurant::operator=(const Restaurant &res) // Copy operator
    {
        if (this != &res)
        {
            delete[] reservation_;

            storedResv_ = res.storedResv_;

            reservation_ = new Reservation[storedResv_];
            for (size_t i = 0; i < storedResv_; i++)
            {
                reservation_[i] = res.reservation_[i];
            }
        }

		return *this;
    }

    Restaurant::Restaurant(Restaurant &&res) // Move constructor
    {
        *this = std::move(res);
    }

    Restaurant &Restaurant::operator=(Restaurant &&res) // Move operator
    {
        if (this != &res)
        {
            storedResv_ = res.storedResv_;
            reservation_ = res.reservation_;
            res.reservation_ = nullptr;
            res.storedResv_ = 0;
        }
        return *this;
    }

    Restaurant::Restaurant(const Reservation *reservations[], size_t cnt)
    {
        reservation_ = nullptr;
        storedResv_ = 0;
        if (reservations != nullptr && cnt > 0)
        {
            storedResv_ = 0;
            reservation_ = new Reservation[cnt];
            for (size_t i = 0; i < cnt; i++)
            {
                reservation_[storedResv_] = *reservations[i];
                storedResv_++;
            }
        }
    }

    Restaurant::~Restaurant()
    {
        if (reservation_ != nullptr) {
            delete[] reservation_;
            reservation_ = nullptr;
        }
    }

    size_t Restaurant::size() const
    {
        return storedResv_;
    }

    void Restaurant::display(std::ostream &os) const
    {
        if (storedResv_ == 0)
        {
            std::cout << "--------------------------\n";
            std::cout << "Fancy Restaurant (CALL_CNT)\n";
            std::cout << "--------------------------\n";
            std::cout << "This restaurant is empty!\n";
            std::cout << "--------------------------\n";
        }
        else
        {
            std::cout << "--------------------------\n";
            std::cout << "Fancy Restaurant (CALL_CNT)\n";
            std::cout << "--------------------------\n";
            for (size_t i = 0; i < storedResv_; i++)
            {
                reservation_[i].display(os);
            }
            std::cout << "--------------------------\n";
        }
    }

    std::ostream &operator<<(std::ostream &out, const Restaurant &res)
    {
        res.display(out);

        return out;
    }
} // namespace sdds
