#include "Dispatcher.h"
#include "Url.h"

#include <iostream>

#include "../common/Exception.h"
#include "../common/Terminator.h"

#include "../controllers/BaseController.h"
#include "../controllers/StudentsController.h"

using namespace std;

int mvc::Dispatcher::dispatch() {
	
	char *pszMethod = getenv("HTTP_METHOD");
	char *pszUri = getenv("HTTP_URL");
	
	if (pszMethod != NULL && pszUri != NULL) {
		
		string sMethod(pszMethod);
		string sUri(pszUri);
		
		Terminator<BaseController> mtController;
		
		try {
						
			Url url(resolveHttpMethod(sMethod), sUri);
			
			if (url.uriStartsWith("/student"))
				mtController = new StudentsController();
				
			if (mtController.isEmpty()) {
				cout << "No handler is found for " << url;
			}
				
			return mtController->handleRequest(url);
		} catch (UrlException ex) {	
			
			cout << "UrlException while processing request " << ex.getMessage();
			return 400;
		} catch (Exception ex) {
			
			cout << "Exception while processing request " << ex.getMessage();
			return 500;
		}
	} else {
		
		cout << "HTTP_METHOD or HTTP_URL environment variable are missing"; 
		
		return 256;
	}

}

