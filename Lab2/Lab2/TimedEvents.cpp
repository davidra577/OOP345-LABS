
#include "TimedEvents.h"
#include <iomanip>


namespace sdds
{
	TimedEvents::TimedEvents()
	{
		m_records = 0;
		
	}

	void TimedEvents::startClock()
	{
		start_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		end_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* c)
	{
		auto seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
		if (m_records < 10)
		{
			this->events[m_records].name = c;
			this->events[m_records].units = "nanoseconds";
			this->events[m_records].duration = seconds;
			m_records++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& events)
	{
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < events.m_records; i++)
			os << std::setw(20) << std::left
			<< events.events[i].name << ' ' << std::setw(12) << std::right
			<< events.events[i].duration.count() << ' '
			<< events.events[i].units << std::endl;
		os << "--------------------------" << std::endl;
		return os;
	}

}