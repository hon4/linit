#include <map>
#include <fstream>
#include "conf_handler.hpp"

std::map<std::string, std::string> read_conf(std::string path) {
	std::map<std::string, std::string> ret;
	std::ifstream oppened_file(path);
	std::string line;

	while (std::getline(oppened_file, line)) {
		if (line.empty() || line[0] == "#") continue;
		size_t xpos = line.find('=');
		if (xpos == std::string::npos) continue; //Skip Bad formatted lines
		std::string key = line.substr(0, xpos);
		ret[key] = line.substr(xpos + 1);
	}
	return ret;
}
