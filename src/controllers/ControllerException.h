#pragma once

class ControllerException : public Exception {
	
public:
	ControllerException(string sMessage) : Exception(sMessage) {}
	virtual ~ControllerException() {};
};