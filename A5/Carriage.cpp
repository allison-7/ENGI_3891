#include "Carriage.h"
#include "Pumpkin.h"

Carriage::Carriage(Pumpkin::Colour c)
	:carriageColour_(c), day_(currentDate())
{
}

Pumpkin::Colour Carriage::colour() const
{
	return this->carriageColour_; //return the carriage colour of the current carriage object
}

Pumpkin* Carriage::change() const
{
	if (day_== currentDate())
	{
		return nullptr; //if the day has not changed do nothing
	}
	else
	{
		return Pumpkin::Create(carriageColour_);//if the day has changed turn a carriage into a pumpkin
	}
}


