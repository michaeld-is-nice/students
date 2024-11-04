#include "Dispatcher.h"

#include <iostream>

#include "../common/Exception.h"
#include "Url.h"

using namespace std;

mvc::Dispatcher::Dispatcher()
{
}

mvc::Dispatcher::~Dispatcher()
{
}

int mvc::Dispatcher::dispatch() {
	
	char *methodEnv = getenv("HTTP_METHOD");
	
	if (methodEnv != NULL) {
		string methodStr(methodEnv);
		
		try {
			Url url(resolveHttpMethod(methodStr), string(""));
		
			return 200;
		} catch (Exception e) {
			
			cout << "Exception while processing request " << e.getMessage() << endl;
			return 500;
		}
	} else {
		
		cout << "HTTP_METHOD environment variable is missing" << endl; 
		
		return 256;
	}

}

