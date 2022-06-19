#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span
{
  private:
	typedef std::vector<int>::iterator vec_it;
	std::vector<int>				   vector_;
	unsigned int					   size_;

  public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	~Span();

	Span &operator=(Span const &rhs);

	void		 addNumber(int num);
	void		 addNumber(int count, int value);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NotEnoughCapacityException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

	class NoSpanExeption : public std::exception
	{
	  public:
		const char *what() const throw();
	};
};

#endif
