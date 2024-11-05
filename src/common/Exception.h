#pragma once
#include <string>
 
using namespace std;

class Exception
{
	string msMessage; 
	
public:
	Exception(string sMessage) : msMessage(sMessage) {};
	virtual ~Exception() {};
	
	string getMessage() { return msMessage; }
};

