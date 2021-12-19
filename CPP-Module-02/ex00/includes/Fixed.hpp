#ifndef FIXED_HPP
#define FIXED_HPP

#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Fixed
{
  private:
	int				 value;
	static const int numFactorialBit = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &);

	Fixed &operator=(const Fixed &);

	int	 getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
