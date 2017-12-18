/*
 * Logger.h
 *
 *  Created on: Dec 18, 2017
 *      Author: kaiser
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>

namespace kgr {

const unsigned int MSG = 0;
const unsigned int ERR = 1;

class Logger {
public:
	Logger();

	void log(unsigned int priority, std::string message);

	virtual ~Logger();
};

} /* namespace kgr */

#endif /* LOGGER_H_ */
