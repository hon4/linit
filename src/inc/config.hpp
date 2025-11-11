#include <map>
#include <fstream>

std::map<std::string, std::string> read_config() {
	std::map<std::string, std::string> ret;
	std::ifstream conf_file("/etc/linit.conf");
	std::string line;
	while (std::getline(conf_file, line)) {
		if (line.empty() || line[0] == '#') continue;
		size_t xpos = line.find('=');
		if (xpos == std::string::npos) continue; //Skip Bad formatted lines
		std::string key = line.substr(0, xpos);
		ret[key] = line.substr(xpos + 1);
	}
	return ret;
}
