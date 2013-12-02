#include "log.h"
#include <iostream>

Log *Log::instance() {
    static Log *_instance = new Log();
    return _instance;
}

void Log::log(const std::string &msg, Level level) {
	Impl::Vector::iterator iter = _logImpls.begin();
	for (; iter != _logImpls.end(); iter++) {
        (*iter)->log(msg, level);
	}
	std::cout << msg << std::endl;
}
