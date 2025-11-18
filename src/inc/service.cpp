#include <iostream>
#include <filesystem>

#include "service.hpp"

bool service_chech_if_exist(char* &service_name);
void service_not_exist(char* &service_name);
int service_start(char* &service_name);
int service_stop(char* &service_name);
int service_status(char* &service_name);
void service_show_help();

int service_main(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			service_show_help();
			return 0;
		}
	}

	if (argc != 3) {
		std::cout << "linit: Invalid command format.\nFor more info use command \"service -h\".\n";
		return 1;
	}

	if (strcmp(argv[2], "start") == 0) {
		return service_start(argv[1]);
	} else if (strcmp(argv[2], "stop") == 0) {
		return service_stop(argv[1]);
	} else if (strcmp(argv[2], "status") == 0) {
		return service_status(argv[1]);
	} else {
		std::cout << "linit: Invalid command format.\nUnrecognized option \"" << argv[2] << "\".\nType -h to show help.\n";
		return 1;
	}

	return 0;
}

bool service_chech_if_exist(char* &service_name) {
	return std::filesystem::exists(std::string("/etc/init.d/") + service_name);
}

void service_not_exist(char* &service_name) {
	std::cout << "linit: Service \"" << service_name << "\" does not exist.\n";
}

int service_start(char* &service_name) {
	if (!service_chech_if_exist(service_name)) {
		service_not_exist(service_name);
	}
	system((std::string("/etc/init.d/") + service_name + " start").c_str());
	return 0;
}

int service_stop(char* &service_name) {
	if (!service_chech_if_exist(service_name)) {
		service_not_exist(service_name);
	}
	system((std::string("/etc/init.d/") + service_name + " stop").c_str());
	return 0;
}

int service_status(char* &service_name) {
	if (!service_chech_if_exist(service_name)) {
		service_not_exist(service_name);
	}
	system((std::string("/etc/init.d/") + service_name + " status").c_str());
	return 0;
}

void service_show_help() {
	std::cout << "\nlinit: service Help\n=====================\n\nA command for managing services.\n\nExample usage:\nCommand                  Description\n--------------------------------------------------------\nservice <name> start     Starts the selected service.\nservice <name> stop      Stops the selected service.\nservice <name> status    Shows status of the selected service.\n\n";
}
