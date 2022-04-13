#ifndef DATA
#define DATA

#include "escape_sequence.hpp"
#include <iostream>
#include <stdint.h>
#include <string>

class Data
{
  public:
	std::string s1;
	int			n;
	std::string s2;

	Data();
	~Data();
	Data(const Data &);
	Data &operator=(const Data &);

};

std::ostream &operator<<(std::ostream &, const Data &);
uintptr_t	serialize(Data *ptr);
Data*		deserialize(uintptr_t raw);
#endif
