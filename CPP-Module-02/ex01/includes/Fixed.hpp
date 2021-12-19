#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include "escape_sequence.hpp"
#include <iostream>
#include <string>
#define EIGHT_BIT 256
class Fixed
{
  private:
	int				 value;
	static const int numFactorialBit = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &);
	Fixed(const int val);
	Fixed(const float val);

	Fixed &operator=(const Fixed &);

	int	 getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int	  toInt(void) const;
};

std::ostream& operator<<(std::ostream& , const Fixed& );
#endif
