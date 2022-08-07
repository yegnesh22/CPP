#include <iostream>
#include <string>
#include <stdlib.h>

void binder_read(std::string &buf)
{
	int value = 42;
	buf = std::to_string(value);
}

int main()
{
	std::string buf;
	binder_read(buf);

	std::cout << buf; 
}

