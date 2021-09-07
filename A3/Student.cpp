#include"Student.h"

Student::Student(unsigned int id, std::string name, Level level)
	:Sid(id), Sname(name), Slevel(level)
{

}
unsigned int Student::id() const
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

