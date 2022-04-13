#include "Convert.hpp"
#include <stdlib.h>

int ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

Convert::Convert() : value(0)
{
}

Convert::Convert(std::string value) : value(value)
{
}

Convert::~Convert()
{
}

Convert::Convert(const Convert &c)
{
	value = c.value;
}

Convert &Convert::operator=(const Convert &c)
{
	value = c.value;
	return *this;
}

bool isNumber(std::string str)
{
	unsigned long i = 0;

	if (str[0] == '-')
		i++;
	while (i < str.length())
	{
		if (std::isdigit(str[i]) == 0)
			return false;
		i++;
	}
	return true;
}

int Convert::getInt()
{
	std::istringstream ss;
	ss = std::istringstream(value);

	if (!isNumber(value))
		throw Convert::cantConvertException();
	int num;
	ss >> num;
	return num;
}

void Convert::printChar()
{
	std::istringstream ss;
	ss = std::istringstream(value);

	char	 *endptr = NULL;
	double num	  = strtod(value.c_str(), &endptr);
	std::cout << "int: ";

	if (!isnan(num) && (strcmp(endptr,"") == 0 || strcmp(endptr,"f") == 0))
	{
		if (ft_isprint(static_cast<int>(num)))
			std::cout << "'" << char(static_cast<int>(num)) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} else
	{
		std::cout << "impossible" << std::endl;
	}
}

void Convert::printInt()
{
	std::istringstream ss;
	ss = std::istringstream(value);

	char	 *endptr = NULL;
	double num	  = strtod(value.c_str(), &endptr);
	std::cout << "int: ";

	if (!isnan(num) && (strcmp(endptr,"") == 0 || strcmp(endptr,"f") == 0))
	{
		std::cout << static_cast<int>(num) << std::endl;
	} else
	{
		std::cout << "impossible" << std::endl;
	}
}

void Convert::printFloat()
{
	std::istringstream ss;
	ss = std::istringstream(value);

	char *endptr = NULL;
	double num	  = strtof(value.c_str(), &endptr);
	std::cout << "float: ";

	if (strcmp(endptr,"") == 0 || strcmp(endptr,"f") == 0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num << "f" << std::endl;
	} else
	{
		std::cout << "impossible" << std::endl;
	}
}

void Convert::printDouble()
{
	std::istringstream ss;
	ss = std::istringstream(value);

	char	 *endptr = NULL;
	double num	  = strtod(value.c_str(), &endptr);
	std::cout << "double: ";

	if (strcmp(endptr,"") == 0 || strcmp(endptr,"f") == 0)
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(1) << num << std::endl;
	} else
	{
		//ここで”f”であることを確認する。その場合だけOKとしてみなす。
		std::cout << "impossible" << std::endl;
	}
}
