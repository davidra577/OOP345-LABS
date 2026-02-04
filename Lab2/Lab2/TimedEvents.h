#ifndef timedevents_h
#define timedevents_h


#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	class TimedEvents
	{
		int m_records;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;

		struct {
			std::string name;
			std::string units;
			std::chrono::steady_clock::duration duration;
		} events[10];

	public:

		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* c);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& events);

	};
}
#endif