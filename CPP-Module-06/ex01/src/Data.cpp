#include "Data.hpp"
#include <stdlib.h>

Data::Data() : s1("aaa"), n(0), s2("bbb")
{
}

Data::~Data()
{
}

Data::Data(const Data &d)
{
	s1 = d.s1;
	n  = d.n;
	s2 = d.s2;
}

Data &Data::operator=(const Data &d)
{
	s1 = d.s1;
	n  = d.n;
	s2 = d.s2;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Data &data)
{
	os << data.s1 << ", " << data.n << ", " << data.s2 ;
	return os;
}

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	 *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
