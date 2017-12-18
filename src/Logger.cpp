/*
 * Logger.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: kaiser
 */

#include "Logger.h"

namespace kgr {

Logger::Logger() {
	std::cout << "Logger initialized" << std::endl;
}

void Logger::log(unsigned int priority, std::string message) {
	switch (priority) {
	case MSG:
		std::cout << message << std::endl;
		break;
	case ERR:
		std::cerr << message << std::endl;
		break;
	default:
		std::cout << "Invalid logging code " << priority << std::endl;
	}
}

Logger::~Logger() {
	std::cout << "Logger terminated" << std::endl;
}

} /* namespace kgr */
