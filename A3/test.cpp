#include "Course.h"
#include <iostream>

int main()
{
   // create some student objects
   Student bbr(123456789,"Bender Bending Rodríguez",Student::Level::Undergraduate);
   Student pjf(234567890,"Philip J Fry",Student::Level::Undergraduate);
   Student tl(345678901,"Turanga Leela",Student::Level::Undergraduate);
   Student jaz(456789012,"Johnathan Anderson Zoidberg",Student::Level::Undergraduate); // Zoidberg's offical name is "John A. Zoidberg" so I had it do it :).
   std::vector<Student> students = {bbr,pjf,tl,jaz};

   // create a couple of course objects
   Course engi_3891(3891,Course::Level::Undergraduate);
   Course phys_3000(3000,Course::Level::Undergraduate,0);

   // register some students
   for(int i = 0; i < 4; i++)
      engi_3891.registerStudent(students[i]);

   phys_3000.registerStudent(bbr,true); // this should work

   // test the accessor methods - also look for any output that seem incorrect
   std::cout << "Course#          : " << engi_3891.number()
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
      std::cout << "Student: " << (students[i]).name()
              << "\nID     : " << (students[i]).id() << std::endl; 

      std::cout << std::endl;
   }

   return 0;
}
