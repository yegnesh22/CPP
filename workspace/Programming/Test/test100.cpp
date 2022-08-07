#include <iostream>
#include <string>
#include <stdlib.h>

void processfn(std::string &path, std::string &buf)
{
	std::string hal = "thermal.hal.service";
	int index, pos;
	std::string index_str;

	if (path.compare(0, hal.length(), hal) == 0) {
		std::cout << "Binder sensor\n";
		pos = path.find_first_of("/");
		std::cout << pos << "\n";
		index_str = path.substr(pos+1, path.length());
		std::cout << index_str << "\n";
		index = atoi(index_str.c_str());
		std::cout << index << "\n";
	} else
		std::cout << "sysfs sensor\n"; 
}

int main()
{
	std::string path = "thermal.hal.service/abcd";
	std::string path1 = "/sys/class/thermal/";
	std::string buf = "10";

	processfn(path, buf);
	processfn(path1, buf);
	return 0;
}
