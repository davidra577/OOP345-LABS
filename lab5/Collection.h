// Name :David Ra
// Student ID :101977205
// Email: dra@myseneca.ca
// Lab 5 (PART 2)
// SECTION: OOP345 NBB
// Date: Feb 23rd 2021
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef sdds_Collection_h
#define sdds_Collection_h
#include <iostream>

namespace sdds
{
	template <class T>
	class Collection
	{
		std::string collectionName;
		T* objects = nullptr;
		size_t arrSize = 0;
		void (*itemAddObserver)(const Collection&, const T&) = nullptr;

	public:
		Collection(std::string name)
		{
			collectionName = name;
		}

		Collection(const Collection&) = delete;

		Collection& operator=(const Collection&) = delete;

		~Collection()
		{
			delete[] objects;
		}

		const std::string& name() const
		{
			return collectionName;
		}

		size_t size() const
		{
			return arrSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			this->itemAddObserver = observer;
		};

		Collection<T>& operator+=(const T& item)
		{
			for (auto i = 0u; i < arrSize; i++)
				if (this->objects[i].title() == item.title())
				{
					return *this;
				}
					
			T* temp = new T[arrSize + 1];

			for (auto i = 0u; i < arrSize; i++)
			{
				temp[i] = this->objects[i];
			}

			temp[arrSize] = item;

			delete[] objects;
			objects = temp;
			arrSize++;

			if (itemAddObserver != nullptr)
			{
				itemAddObserver(*this, objects[arrSize - 1]);
			}
				

			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= arrSize)
			{
				std::string msg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arrSize) + "] items.";
				throw std::out_of_range(msg);
			}

			return objects[idx];
		}

		T* operator[](const std::string& title) const
		{
			for (size_t i = 0; i < arrSize; i++)
			{
				if (objects[i].title() == title)
				{
					return &objects[i];
				}
			}
			return nullptr;
		}


		friend std::ostream& operator<<(std::ostream& out, const Collection<T>& obj)
		{
			for (size_t i = 0; i < obj.size(); i++)
			{
				out << obj[i];
			}
			return out;
		}
	};

}
#endif