#include <iostream>
#include <map>
#include "inc/config.hpp"

std::string linit_version = "0.0.1";
std::map<std::string, std::string> conf = read_config();

void show_ver();

int main(int argc, char *argv[]) {
	show_ver();
	std::cout << "\rTest";
	std::cout << std::flush << "\rTest2\n";
	std::cout << conf["test"];
	return 0;
}

void show_ver() {
	std::cout << "\nlinit " << linit_version << "\n=============\n\nCoded by: hon\nLanguage: C++\n\n";
}
