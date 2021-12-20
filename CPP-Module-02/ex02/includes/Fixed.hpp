#ifndef FIXED_HPP
#define FIXED_HPP
#include "escape_sequence.hpp"
#include <cmath>
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
	bool   operator<(const Fixed &);
	bool   operator>(const Fixed &);
	bool   operator<=(const Fixed &);
	bool   operator>=(const Fixed &);
	bool   operator==(const Fixed &);
	bool   operator!=(const Fixed &);

	Fixed &operator+(const Fixed &);
	Fixed &operator-(const Fixed &);
	Fixed &operator*(const Fixed &);
	Fixed &operator/(const Fixed &);

	Fixed &operator++();
	Fixed  operator++(int);
	Fixed &operator--();
	Fixed  operator--(int);

	int	 getRawBits(void) const;
	void setRawBits(int const raw);

	float				toFloat(void) const;
	int					toInt(void) const;
	static Fixed		 &min(Fixed &, Fixed &);
	static Fixed		 &max(Fixed &, Fixed &);
	const static Fixed &min(const Fixed &, const Fixed &);
	const static Fixed &max(const Fixed &, const Fixed &);
};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
