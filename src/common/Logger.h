#pragma once

#include <string>

class Logger {
	
	bool mOn;
	std::string msLevel;
	std::ostream& mStream;
public:
	Logger(std::ostream& stream, std::string level) : mOn(false), msLevel(level), mStream(stream) {};
	Logger& enable();		
	Logger& operator<< (const std::string&);
	Logger& operator<< (const std::string_view&);
	Logger& operator<< (const char*);
    Logger& operator<< (const int);
};

extern Logger info;
extern Logger err;

