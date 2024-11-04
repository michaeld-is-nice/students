#pragma once
#include <string>
 
using namespace std;

class Exception
{
	string message; 
	
public:
	Exception(string _message) : message(_message) {};
	virtual ~Exception() {};
	
	string getMessage() { return message; }
};

