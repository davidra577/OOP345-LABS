// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 4 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 13th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#include "Restaurant.h"
#include <iostream>

namespace sdds
{
    Restaurant::Restaurant()
    {
        reservs = nullptr;
        storedIndex = 0;
    }

    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
        reservs = nullptr;
        storedIndex = 0;

        if (reservations != nullptr && cnt > 0)
        {
            reservs = new Reservation[cnt];
            for (size_t i = 0; i < cnt; i++)
            {
                reservs[storedIndex] = *reservations[i];
                storedIndex++;
            }
        }


    }

    Restaurant::Restaurant(const Restaurant& res) : reservs{ nullptr }
    {
        *this = res;
    }

    Restaurant& Restaurant::operator=(const Restaurant& res)
    {
        if (this != &res)
        {
            delete[] this->reservs;
            this->storedIndex = res.storedIndex;
            this->reservs = new Reservation[storedIndex];
            for (size_t i = 0; i < storedIndex; i++)
            {
                reservs[i] = res.reservs[i];
            }
        }

        return *this;
    }

    Restaurant::Restaurant(Restaurant&& res) : reservs{ nullptr }
    {
        *this = std::move(res);
    }

    Restaurant& Restaurant::operator=(Restaurant&& res) 
    {
        if (this != &res)
        {
            delete[] reservs;
            storedIndex = res.storedIndex;
            reservs = res.reservs;
            res.reservs = nullptr;
            res.storedIndex = 0;
        }
        return *this;
    }



    Restaurant::~Restaurant()
    {
        delete[] reservs;
        reservs = nullptr;
    }

    size_t Restaurant::size() const
    {
        return storedIndex;
    }

    void Restaurant::display(std::ostream& os) const
    {
        static size_t CALL_CNT = 0;
        CALL_CNT++;
        if (reservs == 0)
        {
            os << "--------------------------\n";
            os << "Fancy Restaurant " << "(" << CALL_CNT << ")\n";
            os << "--------------------------\n";
            os << "This restaurant is empty!\n";
            os << "--------------------------\n";
        }
        else
        {
            os << "--------------------------\n";
            os << "Fancy Restaurant " << "(" << CALL_CNT << ")\n";
            os << "--------------------------\n";
            for (size_t i = 0; i < storedIndex; i++)
            {
                os << reservs[i];
            }
            std::cout << "--------------------------\n";
        }
    }

    std::ostream& operator<<(std::ostream& out, const Restaurant& res)
    {
        res.display(out);
        return out;
    }
} 
