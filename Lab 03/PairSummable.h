// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 3 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 6th 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H

#include <iostream>
#include "Pair.h"

namespace sdds {

    template<typename V, typename K>
    class PairSummable : public Pair<V,K> {
        static V initial;
        static size_t minField;
    public:
        PairSummable() {} 
        PairSummable(const K& key, const V& value = initial) : Pair<V,K>(key,value)
        {
            if (key.size() > minField) {
                minField = key.size();
            }
        }

        bool isCompatibleWith(const PairSummable<V, K>& b) const
        {
            bool ok = false;
            if (this->key() == b.key()) {
                ok = true;
            }
            return ok;
        }

        PairSummable& operator+=(const PairSummable<V, K>& p)
        {
            if (this->key() == p.key()) {
                *this = PairSummable(p.key(), (*this).value() + p.value());
            }
            return *this;
        }

        void display(std::ostream& os) const 
        {
            os.setf(std::ios::left);
            os.width(minField);
            Pair<V, K>::display(os);
            os.setf(std::ios::left);
        }

    };

    
    template <>
    int PairSummable<int,std::string>::initial = 0;
    
    template <>
    std::string PairSummable<std::string, std::string>::initial = "";

    template <typename V, typename K>
    size_t PairSummable<V, K>::minField = 0;
    
    template <>
    PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& p)
    {
        if (this->key() == p.key()) {

            if (this->value().empty()) {
                *this = PairSummable(p.key(), (*this).value() + p.value());
            }
            else
            {
                *this = PairSummable(p.key(), (*this).value() + ", " + p.value());
            }
        }
        return *this;
    }

}

#endif