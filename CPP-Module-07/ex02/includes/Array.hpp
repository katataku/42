#ifndef ARRAY
#define ARRAY

#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
  private:
	T  *array;
	int size;

  public:
	Array() : array(nullptr), size(0) {};
	~Array()
	{
		delete array;
	};
	Array(Array &a)
	{
		array = new T[a.size];
		for (int i = 0; i < a.size; i++)
		{
			array[i] = a.array[i];
		}
		size = a.size;
	}
	Array &operator=(Array &a)
	{
		for (int i = 0; i < a.size; i++)
		{
			array[i] = a.array[i];
		}
		size = a.size;
	};

	Array(unsigned int i)
	{
		array = new T[i];
		size  = i;
	};

	T &operator[](int i)
	{
		if (i < 0 || i >= size)
			throw std::out_of_range("out of range");
		return array[i];
	}
};

#endif
