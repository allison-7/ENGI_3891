#include"Student.h"

Student::Student(ID id, std::string name, Level level)
	:Sid(id), Sname(name), Slevel(level)
{

}
bool Student::operator == (const Student& s) const
{
	return (Sid.year==s.Sid.year && Sid.serial==s.Sid.serial); //access the field of the current student object and the field of the other Student object
}
bool Student::operator != (const Student& s) const
{
	return !(Sid.year==s.Sid.year && Sid.serial==s.Sid.serial);
}
Student::ID Student::id() const
{
	return Sid;
}
std::string Student::name() const
{
	return Sname;
}
Student::Level Student::level() const
{
	return Slevel;
}

