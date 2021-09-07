#include "Pumpkin.h"
#include "Carriage.h"

PumpkinException::PumpkinException(std::string message)
	:message_(message)
{
}

std::string PumpkinException::message() const
{
	return message_;
}

Pumpkin* Pumpkin::Create(Pumpkin::Colour c)
{
	Pumpkin* myPumpkin = new Pumpkin(); //create a pointer to a pumpkin on the heap
	myPumpkin->pumpkinColour_ = c; //assign a colour to the pumpkin
	return myPumpkin;
}

std::vector<Pumpkin> Pumpkin::CreatePumpkins(unsigned int n, Colour c, bool carved)
{
	std::vector<Pumpkin>pumpkins;
	Pumpkin *myPumpkin = new Pumpkin(); 
	for (int i=0; i<n; i++)
	{
		myPumpkin = Create(c);
		if(carved==true)
		{
			myPumpkin->carve(); //called the carve method of the Pumpkin class
		}
		pumpkins.push_back(*myPumpkin); //add the pumpkin to the pumpkins vector
	}
	delete myPumpkin; //deallocate the memory
	return pumpkins;
}

Pumpkin::Colour Pumpkin::colour() const //check the pumpkin colour
{
	return this->pumpkinColour_;
}

bool Pumpkin::carved() const //check if the pumpkin has been carved
{
	return this->carved_;
}

void Pumpkin::carve()
{
	if(carved_==true)
	{
		throw PumpkinException("This pumpkin has already been carved!\n");
	}
	else if(carved_==false)
	{
		carved_ = true; //carve the pumpkin if it has not been carved
	}
}

bool Pumpkin::alight() const //check if the pumpkin has been lit
{
	return alight_;
}

void Pumpkin::light()
{
	if(alight_==true)
	{
		throw PumpkinException("This pumpkin has already been lit!\n");
	}
	else if (carved_==false)
	{
		throw PumpkinException("This pumpkin has not been carved!\n");
	}
	else if(carved_==true)
	{
		alight_ = true; //light the pumpkin if it has been carved and not lit
	}
}
