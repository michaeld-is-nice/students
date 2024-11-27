#include "Dispatcher.h"
#include "Url.h"

#include <iostream>

#include "../common/Exception.h"
#include "../common/Terminator.h"
#include "../common/Logger.h"

#include "../controllers/BaseController.h"
#include "../controllers/StudentsController.h"

#include "../reflect/reflect-main/reflect"

using namespace std;

int mvc::Dispatcher::dispatch() {
	
	char *pszMethod = getenv("HTTP_METHOD");
	char *pszUri = getenv("HTTP_URL");
	
	if (pszMethod != NULL && pszUri != NULL) {
		
		string sMethod(pszMethod);
		string sUri(pszUri);
		
		Terminator<BaseController> mtController;
		
		try {
						
			Url url{resolveHttpMethod(sMethod), sUri};
			
			if (url.uriStartsWith("/student"))
				mtController = new StudentsController();
				
			if (mtController.isEmpty()) {
				err << "No handler is found for " << url << "\n";
			}
				
			return mtController->handleRequest(url);
		} catch (UrlException ex) {	
			
			err << "UrlException while processing request " << ex.getMessage() << "\n";
			return 400;
		} catch (Exception ex) {
			
			err << "Exception while processing request " << ex.getMessage() << "\n";
			return 500;
		}
	} else {
		
		err << "HTTP_METHOD or HTTP_URL environment variable are missing" << "\n"; 
		
		return 256;
	}

}

