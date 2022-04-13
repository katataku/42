#ifndef CONVERT
#define CONVERT

#include "escape_sequence.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <math.h>

class Convert
{
  private:
	std::string value;

  public:
	Convert();
	~Convert();
	Convert(const Convert &);
	Convert &operator=(const Convert &);

	Convert(std::string value);

	int getInt();

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	class cantConvertException : public std::exception
	{
		
	};
};

std::ostream &operator<<(std::ostream &, const Convert &);

#endif
