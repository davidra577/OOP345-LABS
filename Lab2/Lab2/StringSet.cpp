#include <iostream>
#include <string>
#include <fstream>
#include "StringSet.h"



namespace sdds
{
	size_t StringSet::counter = 0;

	StringSet::StringSet() 
	{
		str = nullptr;
		counter = 0;
	}

	StringSet::StringSet(const std::string& name)
	{
		str = nullptr;
		counter = 0;
		std::ifstream file(name);
		std::string temp;
		while (!file.eof()) {
			std::getline(file, temp, ' ');
			counter++;
		}
		str = new std::string[counter];
		file.seekg(0, std::ios::beg);
		for (size_t i = 0; i < counter && !file.eof(); i++) {
			std::getline(file, str[i], ' ');
		}
		file.close();
	}
	
	StringSet::StringSet(const StringSet& obj)
	{
		this->str = nullptr;
		*this = obj;
	}

	StringSet& StringSet::operator=(const StringSet& obj)
	{
		if (this != &obj)
		{
			std::cout << str << std::endl;
			delete[] this->str;
			this->counter = obj.counter;
			this->str = new std::string[counter];

			for (size_t i = 0; i < obj.counter; i++)
			{
				str[i] = obj.str[i];
			}
		}

		return *this;
	}


	size_t StringSet::size() const
	{
		return counter;
	}

	std::string StringSet::operator[](size_t pos) const
	{
		std::string temp;
		if (pos <= counter && pos >= 0)
		{
			if (str == nullptr)
			{
				temp == "";
			}
			else
			{
				temp = str[pos];
			}
		}
		else
		{
			temp = "";
		}
		return temp;
	}


	StringSet::StringSet(StringSet&& other) 
	{
		this->str = nullptr;
		*this = std::move(other);
	}


	StringSet& StringSet::operator=(StringSet&& obj) 
	{
		if (this != &obj)
		{
			delete[] str;
			counter = obj.counter;
			str = obj.str;
			obj.str = nullptr;
		}
		return *this;
	}

	StringSet::~StringSet()
	{
		delete[] str;
		str = nullptr;
	}
}