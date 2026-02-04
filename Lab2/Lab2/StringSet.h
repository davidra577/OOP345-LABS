#ifndef stringset_h
#define stringset_h

#include <string>
namespace sdds
{
	class StringSet
	{
	private:
		static size_t counter;
		std::string* str;

	public:
		StringSet();
		StringSet(const std::string& );
		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);
		~StringSet();
		size_t size() const;
		std::string operator[](size_t) const;
		StringSet(StringSet&&);
		StringSet& operator=(StringSet&&);
	};
}

#endif 