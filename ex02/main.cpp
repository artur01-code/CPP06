#include <cstdlib>
#include "Base.hpp"

Base * generate(void)
{
	Base *output = NULL;
	int nbr = rand() % 3;

	std::cout << "Generate: " << (char)(65 + nbr) << std::endl;
	switch (nbr)
	{
		case 0:
			output = new A();
			break;
		case 1:
			output = new B();
			break;
		case 2:
			output = new C();
			break;
		default:
			output = NULL;
			break;
	}
	return (output);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Base class <A> identified" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Base class <B> identified" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Base class <C> identified" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "Base class <A> identified" << std::endl;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << error.what() << std::endl;
	}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Base class <B> identified" << std::endl;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << error.what() << std::endl;
	}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Base class <C> identified" << std::endl;
		return ;
	}
	catch (std::exception & error)
	{
		std::cerr << error.what() << std::endl;
	}
}

int main(void)
{
	Base *myBase;
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::string(25, '-') << " Test " << i << " " << std::string(25, '-') << std::endl;
		myBase = generate();
		identify(myBase);
		identify(*myBase);
		delete myBase;
	}
	return (0);
}

