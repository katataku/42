#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
  private:
	typedef typename std::stack<T>::container_type c_type;

  public:
	typedef typename c_type::iterator				iterator;
	typedef typename c_type::const_iterator			const_iterator;
	typedef typename c_type::reverse_iterator		reverse_iterator;
	typedef typename c_type::const_reverse_iterator const_reverse_iterator;

	MutantStack() : std::stack<T>() {};
	~MutantStack() {};
	MutantStack(MutantStack const &src) : std::stack<T>(src) {};
	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return *this;
	};
	 void push_back(T num){
		this->c.push_back(num);
	}

	iterator begin()
	{
		return this->c.begin();
	}
	const_iterator begin() const
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
	const_iterator end() const
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		return this->c.rend();
	}
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};

#endif