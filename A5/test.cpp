#include "Pumpkin.h"
#include "Carriage.h"
#include "date.h"
#include <iostream>

/**
* Expected Output:

Colour   : Pumpkin::Colour::Orange
Carved?  : 0
Colour   : Pumpkin::Colour::White
Carved?  : 1
Colour   : Pumpkin::Colour::White
Carved?  : 0
Colour   : Pumpkin::Colour::White
Carved?  : 1
Colour   : Pumpkin::Colour::White
Carved?  : 0
Colour   : Pumpkin::Colour::White
Carved?  : 1
--error message because the pumpkin is already carved--
--error message because the pumpkin is not carved yet--
Colour   : Pumpkin::Colour::White
Carved?  : 1
The pumpkin is lit up.
--error message because the pumpkin is already lit--
Colour of Carriage : Pumpkin::Colour::Blue
Colour of Carriage : Pumpkin::Colour::Teal
Colour   : Pumpkin::Colour::Blue
Carved?  : 0
Colour   : Pumpkin::Colour::Teal
Carved?  : 0

*/

// some overloaded operators used to test your output
#include <map>
std::ostream& operator<<(std::ostream& out, const Pumpkin::Colour c);
std::ostream& operator << (std::ostream& os, const Pumpkin& p);
std::ostream& operator << (std::ostream& os, const Carriage& c);

int main()
{
   //create a single pumpkin, a vector of five pumpkins and then create a carriage
   Pumpkin my_pumpkin = *Pumpkin::Create(Pumpkin::Colour::Orange);
   std::vector<Pumpkin> my_pumpkin_patch = Pumpkin::CreatePumpkins(5,Pumpkin::Colour::White,false);
   Carriage old_carriage(Pumpkin::Colour::Blue);

   //output my_pumpkin
   std::cout << my_pumpkin;

   //lets carve up every second pumpkin from the patch and output the results
   for(unsigned int i = 0; i < my_pumpkin_patch.size(); i += 2)
   {
      my_pumpkin_patch[i].carve();
   }

   for(unsigned int i = 0; i < my_pumpkin_patch.size(); i++)
   {
      std::cout << my_pumpkin_patch[i];
   }

   // try to carve a pumpkin that is already carved
   try
   {
      my_pumpkin_patch[2].carve();
   }
   catch(PumpkinException pe)
   {
      std::cout << pe.message();
   }

   // try to light a pumpkin that is carved and one that is not carved
   try
   {
      my_pumpkin_patch[0].light();
      my_pumpkin_patch[1].light();
   }
   catch(PumpkinException pe)
   {
      std::cout << pe.message();
   }
   std::cout << my_pumpkin_patch[0];

   // try to re-light the previous pumpkin
   try
   {
      my_pumpkin_patch[0].light();
   }
   catch(PumpkinException pe)
   {
      std::cout << pe.message();
   }

   //output the old carriage
   std::cout << old_carriage;

   //create a new carriage
   Carriage new_carriage(Pumpkin::Colour::Teal);

   //output the new carriage
   std::cout << new_carriage;

   //change both carriages back to pumpkins and check to make sure they are not null. If not output the results.
   Pumpkin* old_pumpkin = old_carriage.change();
   if(old_pumpkin == nullptr)
   {  
      delete old_pumpkin;  
   }
   else
   {
      std::cout << *old_pumpkin;
      delete old_pumpkin;
   }

   Pumpkin* new_pumpkin = new_carriage.change();
   if(new_pumpkin == nullptr)
   {
      delete new_pumpkin;  
   }
   else
   {
      std::cout << *new_pumpkin;
   }
   
   return 0;
}




/**
*
*   Will return the current date relative to the date of the start of the program.
*
*   Note: Due to lack of understanding of how to implement this function or calculate the date,
*         I will cheat by creating a global variable and I will implement the function so that 
*         everytime the function is called, it increments date (as seen below) by one. 
*
*   @returns the current date
*/
int date = 0;

int currentDate()
{
   return date++;
}



std::ostream& operator<<(std::ostream& out, const Pumpkin::Colour c)
{
   static std::map<Pumpkin::Colour, std::string> strings;
   if (strings.size() == 0){
   #define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Pumpkin::Colour::Orange);
        INSERT_ELEMENT(Pumpkin::Colour::White);
        INSERT_ELEMENT(Pumpkin::Colour::Blue);
        INSERT_ELEMENT(Pumpkin::Colour::Teal);
   #undef INSERT_ELEMENT
   }
   return out << strings[c];   
}



std::ostream& operator << (std::ostream& os, const Pumpkin& p)
{
   os << "Colour   : " << p.colour()
    << "\nCarved?  : " << p.carved() << "\n";
    if(p.alight())
    {
       os << "The pumpkin is lit up.\n";
    }
    return os;
}



std::ostream& operator << (std::ostream& os, const Carriage& c)
{
   os << "Colour of Carriage : " << c.colour() << "\n";
   return os;
}
