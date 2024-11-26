#include "Logger.h"

#include <string>
#include <iostream>

Logger& Logger::enable() {
	mOn = true;
	return *this;
}

Logger& Logger::operator<< (const std::string& sMessage) {
	if (mOn)
		mStream << sMessage;
		
	return *this;
}

Logger& Logger::operator<< (const std::string_view& sMessage) {
	if (mOn)
		mStream << sMessage;
		
	return *this;
}

Logger& Logger::operator<< (const char* pszMessage) {
	if (mOn)
		mStream << pszMessage;
		
	return *this;	
}

Logger& Logger::operator<< (const int iMessage) {
    if (mOn)
        mStream << iMessage;

    return *this;
}
