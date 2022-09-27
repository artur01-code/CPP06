#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data
{
	public:
		Data(void);
		Data(const Data &rhs);
		Data& operator=(const Data &rhs);
		~Data(void);

	private:
		std::string	_string;
		char		_c;
		int			_i;
		float		_f;
		double		_d;

	public:
		std::string getString(void);
		char getChar(void);
		int	getInt(void);
		float	getFloat(void);
		double	getDouble(void);
		void setString(std::string string);
		void setChar(char c);
		void setInt(int i);
		void setFloat(float f);
		void setDouble(double d);
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);
};

#endif