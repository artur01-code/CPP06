#include "Data.hpp"


int main(void)
{
	Data	*	myData = new Data;
	uintptr_t	rawData;

	myData->setString("Hello World");
	myData->setChar('G');
	myData->setInt(42);
	myData->setFloat(08.15f);
	myData->setDouble(4711.0);
	std::cout << "string : " << myData->getString() << std::endl;
	std::cout << "char   : " << myData->getChar() << std::endl;
	std::cout << "int    : " << myData->getInt() << std::endl;
	std::cout << "float  : " << myData->getFloat() << std::endl;
	std::cout << "double : " << myData->getDouble() << std::endl;
	std::cout << "Pointer to data structure before serialization: " << &myData << std::endl;
	
	rawData = myData->serialize(myData);

	std::cout << std::endl;

	myData = myData->deserialize(rawData);
	
	std::cout << "Pointer to data structure after deserialization: " << &myData << std::endl;
	std::cout << "string : " << myData->getString() << std::endl;
	std::cout << "char   : " << myData->getChar() << std::endl;
	std::cout << "int    : " << myData->getInt() << std::endl;
	std::cout << "float  : " << myData->getFloat() << std::endl;
	std::cout << "double : " << myData->getDouble() << std::endl;
	delete myData;
	return (0);
}
