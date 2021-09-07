#include"PumpkinPatch.h"
#include<iostream>
PumpkinPatch PumpkinPatch::Create(size_t n, Pumpkin::Colour c)
{
	std::vector<Pumpkin*> myPatch;
	for (size_t i=0; i<n; i++)
	{
		Pumpkin* myPumpkin =new Pumpkin(); //create a new pumpkin on the heap
		myPumpkin->pumpkinColour_ =c;
		myPatch.push_back(myPumpkin); //add a pumpkin pointer to myPatch
	}
	return PumpkinPatch(myPatch);
}

PumpkinPatch::PumpkinPatch(std::vector<Pumpkin*> pPointers)
	:myPatch_(pPointers)
{
}
PumpkinPatch::PumpkinPatch(const PumpkinPatch& otherPatch)
{
	this->myPatch_=otherPatch.myPatch_; //copy myPatch_
}
PumpkinPatch::~PumpkinPatch()
{
	for (size_t i=0; i<myPatch_.size(); i++)
		delete myPatch_[i];
}
PumpkinPatch& PumpkinPatch::operator = (const PumpkinPatch& otherPatch)
{
	//copy the pumpkins from myPatch_ to otherPatch
	for (size_t i=0; i<myPatch_.size(); i++)
               this->myPatch_[i]=otherPatch.myPatch_[i];
	return *this; 
}
size_t PumpkinPatch::size() const
{
	return myPatch_.size(); //return the size of myPatch_
}
Pumpkin& PumpkinPatch::operator[] (size_t i)
{
	return *myPatch_[i]; //return the address of a pumpkin in myPatch_
}
Pumpkin** PumpkinPatch::begin()
{
	Pumpkin** it = &myPatch_[0];
	return it; //return a pointer to the address of the beginning of myPatch_
}
Pumpkin** PumpkinPatch::end()
{
	int end = myPatch_.size();
	Pumpkin** it = &myPatch_[end]; 
	return it; //return a pointer to the address of the end of myPatch_
}
size_t PumpkinPatch::carve()
{
	unsigned int s = 0;
	for (size_t i=0; i<myPatch_.size(); i++)
	{
		try{myPatch_[i]->carve();} //check if a pumpkin has been carved
		catch (PumpkinException e) 
		{
			std::cout<<e.message()<<std::endl;
		}
		if (myPatch_[i]->carved()) //if a pumpkin was carved add 1 to s
			s++;
	}
	return s;
}
size_t PumpkinPatch::light()
{
	unsigned int l = 0;
	for (size_t i=0;i<myPatch_.size(); i++)
	{
		try{myPatch_[i]->light();} //check to see if each pumpkin is lit
		catch (PumpkinException e)
		{
			std::cout<<e.message()<<std::endl;
		}
		if(myPatch_[i]->alight()) //access the alight() method of the pumpkin class
			l++; 
	}
	return l;
}
std::vector<Carriage> PumpkinPatch::makeCarriages()
{
	std::vector<Carriage> carriages;
	for (size_t i=0; i<myPatch_.size(); i++)
	{
		Carriage c(myPatch_[i]->pumpkinColour_);
		carriages.push_back(c);
		delete myPatch_[i]; //delete each pumpkin after you make a carriage
	}
	return carriages;
}
