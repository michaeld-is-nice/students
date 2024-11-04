#pragma once

#include <string>

#include "../common/Exception.h"

using namespace std;

namespace mvc
{

typedef enum {
	GET, POST, PATCH, PUT
} HTTP_METHOD;

class UrlException : public Exception {
	
public:
	UrlException(string message) : Exception(message) {}
	virtual ~UrlException() {};
};

HTTP_METHOD resolveHttpMethod(string&) throw(UrlException);
	
class Url
{
	HTTP_METHOD method;
	string url;
	
public:
	Url(HTTP_METHOD m, string u) : method(m), url(u) {};
	~Url() {};
};

}

