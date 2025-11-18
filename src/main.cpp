#include <iostream>
#include <map>
#include "inc/config.hpp"
#include "inc/service.hpp"
#include "inc/main_functions.hpp"

std::string linit_version = "0.0.1";
std::map<std::string, std::string> conf = read_config();

int main(int argc, char *argv[]) {
	if (strcmp(argv[0], "service") == 0) {
		return service_main(argc, argv);
	}
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-v") == 0) {
			show_ver();
			return 0;
		}
	}
	std::cout << "\rTest";
	std::cout << std::flush << "\rTest2\n";
	std::cout << conf["test"];
	return 0;
}
