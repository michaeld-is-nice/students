#pragma once

#include <string>
#include <iostream>

#include "../common/Exception.h"
#include "../common/Logger.h"

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

HTTP_METHOD resolveHttpMethod(const string&);
	
class Url
{
	HTTP_METHOD mMethod;
	string mUri;
	
public:
	Url(HTTP_METHOD method, const string uri) : mMethod{method}, mUri{uri} {};
	~Url() {};
	
	friend Logger& operator<< (Logger&, const Url&);
	
	bool uriStartsWith(const string& prefix) const;
	bool isComply(const HTTP_METHOD method, const string& prefix) const;
	
	HTTP_METHOD getMethod() { return mMethod; }
	string getUri() { return mUri; }
	
private:
	string methodAsString() const;
};

}

