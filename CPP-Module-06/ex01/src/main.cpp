#include "Data.hpp"

int main(void)
{
	Data *data = new Data();

	std::cout << "data:" << data << std::endl;
	std::cout << "*data:" << *data << std::endl;

	std::cout << std::endl;

	uintptr_t ptr = serialize(data);
	std::cout << "ptr:" << ptr << std::endl;
	std::cout << "ptr:" << deserialize(ptr) << std::endl;
	std::cout << "*ptr:" << *deserialize(ptr) << std::endl;

	return (0);
}
