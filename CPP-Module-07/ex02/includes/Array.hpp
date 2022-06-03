#ifndef ARRAY
#define ARRAY

#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
  private:
	T  *array_;
	int size_;

  public:
	Array() : array_(nullptr), size_(0) {};
	~Array()
	{
		delete array_;
	};
	Array(const Array &a)
	{
		array_ = new T[a.size_];
		for (int i = 0; i < a.size_; i++)
		{
			array_[i] = a.array_[i];
		}
		size_ = a.size_;
	}
	Array &operator=(const Array &a)
	{
		for (int i = 0; i < a.size_; i++)
		{
			array_[i] = a.array_[i];
		}
		size_ = a.size_;
	};

	Array(unsigned int i)
	{
		array_ = new T[i];
		size_  = i;
	};

	T &operator[](int i)
	{
		if (i < 0 || i >= size_)
			throw std::out_of_range("out of range");
		return array_[i];
	}

	const T &operator[](int i) const
	{
		if (i < 0 || i >= size_)
			throw std::out_of_range("out of range");
		return array_[i];
	}

	int size() const
	{
		return size_;
	}
};

#endif
