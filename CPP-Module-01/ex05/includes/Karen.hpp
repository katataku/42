#ifndef Karen_HPP
#define Karen_HPP

#include "escape_sequence.hpp"
#include <iostream>
#include <string>

class Karen
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Karen();
	~Karen();
	void complain(std::string level);
};

#endif
