#include <iostream>
#include <map>
#include "inc/config.hpp"

std::string linit_version = "0.0.1";
std::map<std::string, std::string> conf = read_config();

int main(int argc, char *argv[]) {
	std::cout << "\rTest";
	std::cout << std::flush << "\rTest2\n";
	std::cout << conf["test"];
	return 0;
}
