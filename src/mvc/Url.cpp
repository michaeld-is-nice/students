#include "Url.h"

#include <string>


using namespace std;

mvc::HTTP_METHOD mvc::resolveHttpMethod(string& strMethod) throw(UrlException) {
	
	if (strMethod == "GET")
		return GET;
	
	throw UrlException(string("Wrong HTTP method ") + strMethod);	
}

