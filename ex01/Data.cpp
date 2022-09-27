#include "Data.hpp"

Data::Data(void)
{

}

Data::Data(const Data &rhs)
{
	*this = rhs;
}

Data& Data::operator=(const Data &rhs)
{
	delete this;
	*this = rhs;
	return (*this);
}

Data::~Data(void)
{

}

std::string Data::getString(void)
{
	return (this->_string);
}

char Data::getChar(void)
{
	return (this->_c);
}

int Data::getInt(void)
{
	return (this->_i);
}

float Data::getFloat(void)
{
	return (this->_f);
}

double Data::getDouble(void)
{
	return (this->_d);
}

void Data::setString(std::string string)
{
	this->_string = string;
}

void Data::setChar(char c)
{
	this->_c = c;
}

void Data::setInt(int i)
{
	this->_i = i;
}

void Data::setFloat(float f)
{
	this->_f = f;
}

void Data::setDouble(double d)
{
	this->_d = d;
}

uintptr_t Data::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Data::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
