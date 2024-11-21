#include "Url.h"

#include <string>
#include <iostream>


using namespace std;
using namespace mvc;

HTTP_METHOD mvc::resolveHttpMethod(const string& sMethod) {
	
	if (sMethod == "GET")
		return GET;
	if (sMethod == "POST")
		return GET;
	if (sMethod == "PUT")
		return PUT;
	if (sMethod == "PATCH")
		return PATCH;
	
	throw UrlException(string("Wrong HTTP method ") + sMethod);	
}

Logger& mvc::operator<< (Logger& log, const Url& url) {

    log << "Url: { method: " << url.methodAsString() << ", uri: " << url.mUri << "}";

    return log;
}

bool Url::uriStartsWith(const string& sPrefix) const {
	
	return mUri.compare(0, sPrefix.length(), sPrefix) == 0;
}

bool Url::isComply(const HTTP_METHOD method, const string& sPrefix) const {
	
	return  method == mMethod && uriStartsWith(sPrefix);
}

string Url::methodAsString() const {

	switch(mMethod) {
		case GET:
			return "GET";
		default:
			return string("Unsupported HTTP method ") + std::to_string(mMethod);
	}
}

