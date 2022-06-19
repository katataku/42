#include "Span.hpp"

Span::Span() : size_(0)
{
}
Span::Span(unsigned int N) : size_(N)
{
	vector_.reserve(N);
}
Span::Span(const Span &src)
{
	*this = src;
}
Span::~Span()
{
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->size_	  = rhs.size_;
		this->vector_ = rhs.vector_;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (vector_.size() == size_)
	{
		throw NotEnoughCapacityException();
	}
	vector_.push_back(num);
};

void Span::addNumber(int count, int value)
{
	if (vector_.size() == size_)
	{
		throw NotEnoughCapacityException();
	}
	vector_.insert(vector_.end(), count, value);
};

unsigned int Span::shortestSpan()
{
	if (vector_.size() < 2)
	{
		throw NoSpanExeption();
	}

	unsigned int res = std::abs(vector_[0] - vector_[1]);
	for (std::vector<int>::iterator lhs_it = this->vector_.begin();
		 lhs_it != this->vector_.end();
		 lhs_it++)
	{
		for (std::vector<int>::iterator rhs_it = lhs_it + 1;
			 rhs_it != this->vector_.end();
			 rhs_it++)
		{
			unsigned int calc_res = std::abs(*lhs_it - *rhs_it);
			if (res > calc_res)
				res = calc_res;
		}
	}
	return res;
};

unsigned int Span::longestSpan()
{
	if (vector_.size() < 2)
	{
		throw NoSpanExeption();
	}

	std::vector<int>::iterator max_itr
		= std::max_element(vector_.begin(), vector_.end());
	std::vector<int>::iterator min_itr
		= std::min_element(vector_.begin(), vector_.end());

	return (*max_itr - *min_itr);
};

const char *Span::NotEnoughCapacityException::what() const throw()
{
	return "This instance has not enough capacity.";
}

const char *Span::NoSpanExeption::what() const throw()
{
	return "This instance has no span.";
}