#include <iostream>
#include "main_functions.hpp"

void show_ver(std::string subprogram) {
	std::cout << "\nlinit " << linit_version << "\n=============\n\n";
	if (!subprogram.empty()) {
		std::cout << "SubProgram: " << subprogram << "\n";
	}
	std::cout << "Coded by: hon\nLanguage: C++\n\n";
}
