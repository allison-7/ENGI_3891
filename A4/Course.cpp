#include "Course.h"
std::vector<int> studentSerial;
std::vector<int> studentYear;
Course::Course(unsigned int number, Level level, unsigned int capacity)
        : v_course(number), v_level(level), v_capacity(capacity), v_seatsRemaining(capacity), enrolled(0), ClassList()
{
}
unsigned int Course::number() const
{
	return v_course;
}
Course::Level Course::level() const
{
	return v_level;
}
bool Course::registerStudent(Student s, bool overriderLimits)
{
        if(v_seatsRemaining != 0)
	{
		v_seatsRemaining--; 
		enrolled++;
		ClassList.push_back(s.name());
                return true;
	}
        else if (overriderLimits==true)
        {
		v_seatsRemaining--;
                enrolled++;
		ClassList.push_back(s.name());
                return true;
        }
        else if (v_seatsRemaining == 0)
                return false;
        else
                return false;
}
Course& Course::operator << (Student s) //students must be registered with this operator except if you want to override the class size limit
{	
	int j=0;
	if (studentSerial.size()!=0 && studentYear.size()!=0 && v_seatsRemaining>0) //loop through the class list if there is room and if there are students registered
	{
		for (int i=0; i<studentSerial.size();i++)
		{
			if(s.id().serial==studentSerial[i] && s.id().year==studentYear[i]) //check to see if the student is already registered
			{
				throw std::string("Error, this student is already registered for this course\n");
				j++;
				break;
			}
		}
	}
	if (v_seatsRemaining<=0) //check to see if there is room
	{
		throw std::string("Error, this course is full\n");
		j++;
	}		
	if(j==0) //this condition is to ensure registerStudent is only called if no errors were found
	{
		Course::registerStudent(s);
		studentSerial.push_back(s.id().serial);
		studentYear.push_back(s.id().year);
	}
	return *this; //return a reference to the course
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
std::vector<std::string> Course::classList() const
{
	return ClassList;
}

