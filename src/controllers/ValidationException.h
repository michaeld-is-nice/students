#pragma once

class ValidationException : public ControllerException
{
public:
	ValidationException(string mMessage) : ControllerException(mMessage);
	virtual ~ValidationException() {};

};

