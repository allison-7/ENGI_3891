#include "Course.h"

Course::Course(unsigned int number, Level level, unsigned int capacity)
	: v_course(number), v_level(level), v_capacity(capacity), v_seatsRemaining(capacity), enrolled(0)
{
}
bool Course::registerStudent(bool overriderLimits)
{
	if(v_seatsRemaining != 0)
	{
		v_seatsRemaining--;
		enrolled++;
		return true;
	}
	else if (overriderLimits==true)
	{
		v_seatsRemaining--;
		enrolled++;
		return true;
	}
	else if (v_seatsRemaining == 0)
		return false;
	else
		return false;
}

unsigned int Course::capacity() const
{
	return v_capacity;
}

unsigned int Course::enrolment() const
{
	return enrolled;
}

int Course::seatsRemaining() const
{
	return v_seatsRemaining;
}

