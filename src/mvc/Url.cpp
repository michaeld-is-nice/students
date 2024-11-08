#include "Url.h"

#include <string>
#include <iostream>


using namespace std;
using namespace mvc;

HTTP_METHOD mvc::resolveHttpMethod(const string& sMethod) throw(UrlException) {
	
	if (sMethod == "GET")
		return GET;
	
	throw UrlException(string("Wrong HTTP method ") + sMethod);	
}

ostream& mvc::operator<< (ostream& s, const Url& url) {

    s << "Url: { method: " << url.methodAsString() << ", uri: " << url.mUri << "}";

    return s;
}

bool Url::uriStartsWith(const string& sPrefix) {
	
	return mUri.compare(0, sPrefix.length(), sPrefix) == 0;
}

bool Url::isComply(const Url& url, HTTP_METHOD method, const string& sPrefix) {
	
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

