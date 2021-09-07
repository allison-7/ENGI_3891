#include "Course.h"
#include<iostream>

int main (int argc, char * argv[]) 
{
	Course ENGI3891 (3891, Course::Level::Undergraduate);
	for (int i =1; i <101 ; i++) //if i==101 course is filled or if i<101 course is not full
	{
		if (ENGI3891.registerStudent() == true)
        	{
                	std::cout<<"registerStudent() successful.\n";
        	}
        	else std::cout<<"registerStudent() failed.\n"; //if i>101 then registerStudent() should fail
	}
	if(ENGI3891.enrolment()==100)
		ENGI3891.registerStudent(true);
	if (ENGI3891.enrolment() == 101 || ENGI3891.enrolment()==100) 
		std::cout<<"enrolment() successful.\n";
	else 
		std::cout<<"enrolment() failed.\n";
	if(ENGI3891.seatsRemaining() == -1) 
		std::cout<<"seatsRemaining() successful.\n";
	else std::cout<< "seatsRemaining() failed.\n";
	return 0;
}
