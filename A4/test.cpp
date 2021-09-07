#include "Course.h"
#include "Student.h"
#include <iostream>

/**
*
* Expected Output:

--- The first occurance of an error message from using the student registration operator ---
--- The second occurance of an error message from using the student registration operator ---
Course#          : 3891
Level            : Course::Level::Undergraduate
Students Enrolled: 4
Capacity         : 100
Seats left       : 96
Students         : Bender Bending Rodríguez
                   Philip J Fry
                   Turanga Leela
                   Johnathan Anderson Zoidberg
                   
Course#          : 3000
Level            : Course::Level::Undergraduate
Students Enrolled: 1
Capacity         : 0
Seats left       : -1
Students         : Bender Bending Rodríguez
                   
Student: Bender Bending Rodríguez
Level  : Student::Level::Undergraduate
ID     : 201623456
Student: Philip J Fry
Level  : Student::Level::Undergraduate
ID     : 201634567
Student: Turanga Leela
Level  : Student::Level::Undergraduate
ID     : 201645678
Student: Johnathan Anderson Zoidberg
Level  : Student::Level::Undergraduate
ID     : 201612345
Johnathan Anderson Zoidberg is equal to Johnathan Anderson Zoidberg
Bender Bending Rodríguez is not equal to Philip J Fry

*
*/



// some overloaded operators used to test your output
#include <map>
std::ostream& operator<<(std::ostream& out, const Course::Level lev)
{
   static std::map<Course::Level, std::string> strings;
   if (strings.size() == 0){
   #define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Course::Level::Undergraduate);
        INSERT_ELEMENT(Course::Level::Postgraduate); 
   #undef INSERT_ELEMENT
   }
   return out << strings[lev];   
}

std::ostream& operator<<(std::ostream& out, const Student::Level lev)
{
   static std::map<Student::Level, std::string> strings;
   if (strings.size() == 0){
   #define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Student::Level::Undergraduate);
        INSERT_ELEMENT(Student::Level::Postgraduate); 
   #undef INSERT_ELEMENT
   }
   return out << strings[lev];
}

int main()
{
   // create some student objects
   Student bbr({.year = 2016,.serial = 23456},"Bender Bending Rodríguez",Student::Level::Undergraduate);
   Student pjf({.year = 2016,.serial = 34567},"Philip J Fry",Student::Level::Undergraduate);
   Student tl({.year = 2016,.serial = 45678},"Turanga Leela",Student::Level::Undergraduate);
   Student jaz({.year = 2016,.serial = 12345},"Johnathan Anderson Zoidberg",Student::Level::Undergraduate);
   Student aw({.year = 2015,.serial = 12345},"Amy Wong",Student::Level::Undergraduate);
   std::vector<Student> students = {bbr,pjf,tl,jaz,aw};

   // create a couple of course objects
   Course engi_3891(3891,Course::Level::Undergraduate);
   Course phys_3000(3000,Course::Level::Undergraduate,0);

   // register some students
   for(int i = 0; i < 4; i++)
      //engi_3891.registerStudent(students[i]);
      engi_3891<<students[i];
   //register a student using the overloaded bitshift operator
   //engi_3891 << students[3];
   engi_3891<<students[4]; //this should work since the year is different
   //this should output an error message due to a repeated registration
   try
   {
      engi_3891 << students[2];
   }
   catch(std::string s)
   {
      std::cout << s;
   }
   //this should output an error message
   try
   {
      engi_3891 << students[4];
   }
   catch(std::string s)
   {   
      std::cout << s;
   }
   //this should work
   phys_3000.registerStudent(bbr,true);
  
   //this should output an error message due to enrolment meeting or exceeding capacity
  try
   {
      phys_3000 << students[2];
   }
   catch(std::string s)
   {
      std::cout << s;
   }

   // test the accessor methods - also look for any output that may seem incorrect
   std::cout << "Course#          : " << engi_3891.number()
           << "\nLevel            : " << engi_3891.level()
           << "\nStudents Enrolled: " << engi_3891.enrolment()
           << "\nCapacity         : " << engi_3891.capacity()
           << "\nSeats left       : " << engi_3891.seatsRemaining() << std::endl;
   std::cout << "Students         : ";
   for(int i = 0; i < (engi_3891.classList()).size(); i++)
   {
      std::cout << (engi_3891.classList())[i] << "\n                   ";
   }

   std::cout << std::endl;

   std::cout << "Course#          : " << phys_3000.number()
           << "\nLevel            : " << phys_3000.level()
           << "\nStudents Enrolled: " << phys_3000.enrolment()
           << "\nCapacity         : " << phys_3000.capacity()
           << "\nSeats left       : " << phys_3000.seatsRemaining() << std::endl;
   std::cout << "Students         : ";
   for(int i = 0; i < (phys_3000.classList()).size(); i++)
   {
      std::cout << (phys_3000.classList())[i] << "\n                   ";
   }

   std::cout << std::endl;

   for(int i = 0; i < students.size(); i++)
   {
      std::cout << "Student: " << (students[i]).name() << std::endl
                << "Level  : " << (students[i]).level() << std::endl
                << "ID     : " << ((students[i]).id()).year << ((students[i]).id()).serial << std::endl;
   }

   //Update: Forgot to do a check for the equivilency operators for Student. Here you go.
   Student jaz2({.year = 2016,.serial = 12345},"Johnathan Anderson Zoidberg",Student::Level::Undergraduate);
   if(jaz == jaz2)
      std::cout << jaz2.name() << " is equal to " << jaz.name() << "\n";
   else
      std::cout << jaz2.name() << " is not equal to " << jaz.name() << "\n";

   if(bbr != pjf)
      std::cout << bbr.name() << " is not equal to " << pjf.name() << "\n";
   else
      std::cout << bbr.name() << " is equal to " << pjf.name() << "\n";

   return 0;
}  
