#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <limits>
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

// int handlePseudo(std::string input)
// {
// 	int	i;
// 	std::string pseudoArr[8] = {"inff", "+inff", "-inff", "nanf", "inf", "+inf", "-inf", "nan"};
	
// 	for (i = 0; i < 8; i++)
// 		if (!input.compare(pseudoArr[i]))
// 			break;
// 	if (i < 8)
// 	{
// 		//print char
// 		std::cout << "char: Non displayable" << std::endl;
// 		//print int
// 		std::cout << "int: Non displayable" << std::endl;
// 		//print float
// 		std::string toPrint;
// 		if (i < 4)
// 			toPrint = pseudoArr[i];
// 		else if (i == 7)
// 			toPrint = "nanf";
// 		else
// 			toPrint = "Undefined behavior";
// 		std::cout << "float: " << toPrint << std::endl;
// 		//print double
// 		if (i > 4)
// 			toPrint = pseudoArr[i];
// 		else if (i == 3)
// 			toPrint = "nan";
// 		else
// 			toPrint = "Undefined behavior";
// 		std::cout << "double: " << toPrint << std::endl;
// 		return (1);
// 	}
// 	return (0);
// }

/*
gets called when only one character is given as input
*/
int handleChar(char c)
{
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//print the other types with a static cast
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
	return (0);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error:\nInvalid amount of arguments" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	// int			i;
	// char		c;
	float		f = 0;
	double		d = 0;
	char **endptr;

	//sets the standart to using fixed point numbers and the precision of 1
	std::cout << std::fixed << std::setprecision(1);

	// if (handlePseudo(argv[1]))
	// 	return (0);
	if (isdigit(argv[1][0]) || input.size() > 1)
	{
		endptr = new char*;
		d = std::strtod(argv[1], endptr);
		// f = std::strtof(argv[1], endptr);
		f = static_cast<float>(d);
		// != f because its a float number
		if (**endptr && (strlen(*endptr) != 1 || **endptr != 'f'))
		{
			std::cout << "Error:\n Invalid input. Enter only one character." << std::endl;
			return (1);
		}
		delete endptr;
	}
	else
		return (handleChar(argv[1][0]));
	//Printing part
	//check for limits
	//print char
	if (isprint(f))
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//print int
	if (d <= INT_MAX && d >= INT_MIN) //works?
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: Non displayable" << std::endl;
	//print float
	if (d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::min())
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: Non displayable" << std::endl;
	//print double
	std::cout << "double: " << d << std::endl;
	return (0);
}
