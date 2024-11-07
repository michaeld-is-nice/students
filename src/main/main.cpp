#include <iostream>

#include "../mvc/Dispatcher.h"
#include "../common/Logger.h"

using namespace std;
using namespace mvc;

Logger info(std::cout, " INFO");
Logger err(std::cerr, "ERROR");

int main(int argc, char **argv)
{
#if __cplusplus > 201703L	
	cout << "C++ version 20" << endl;
#endif	

	err.enable();
	
	Dispatcher dispatcher;
	
	return dispatcher.dispatch(); 
}
