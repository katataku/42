#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed::Fixed(const int val)
{
//	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(val * EIGHT_BIT);
}
Fixed::Fixed(const float val)
{
//	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(val * EIGHT_BIT));
}

Fixed &Fixed::operator=(Fixed const &f)
{
//	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(f.getRawBits());
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (float) this->getRawBits() / EIGHT_BIT;
}
int Fixed::toInt(void) const
{
	return this->value / EIGHT_BIT;
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed &f)
{
	return (getRawBits() < f.getRawBits());
}
bool Fixed::operator>(const Fixed &f)
{
	return (getRawBits() > f.getRawBits());
}
bool Fixed::operator<=(const Fixed &f)
{
	return (getRawBits() <= f.getRawBits());
}
bool Fixed::operator>=(const Fixed &f)
{
	return (getRawBits() >= f.getRawBits());
}
bool Fixed::operator==(const Fixed &f)
{
	return (getRawBits() == f.getRawBits());
}
bool Fixed::operator!=(const Fixed &f)
{
	return (getRawBits() != f.getRawBits());
}

Fixed &Fixed::operator+(const Fixed &f)
{
	setRawBits((this->toFloat() + f.toFloat()) / EIGHT_BIT);
	return *this;
}
Fixed &Fixed::operator-(const Fixed &f)
{
	setRawBits((this->toFloat() - f.toFloat()) / EIGHT_BIT);
	return *this;
}
Fixed &Fixed::operator*(const Fixed &f)
{
	long long tmp = (this->toFloat() * f.toFloat());
	setRawBits( tmp * EIGHT_BIT);
	return *this;
}
Fixed &Fixed::operator/(const Fixed &f)
{
	setRawBits((this->toFloat() / f.toFloat()) / EIGHT_BIT);
	return *this;
}

Fixed &Fixed::operator++()
{	
	value++;
	return *this;
}
Fixed  Fixed::operator++(int)
{	
	Fixed old = *this;
	value++;
	return old;

}


Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	if (&a <= &b)
		return Fixed(a);
	return Fixed(b);
}
Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	std::cout << "a:"<<a.toFloat() << "b:"<<b.toFloat() << std::endl;
	if (&a >= &b)
		return Fixed(a);
	return Fixed(b);
}
