#include <iostream>

#include "../mvc/Dispatcher.h"

using namespace std;
using namespace mvc;

int main(int argc, char **argv)
{
#if __cplusplus > 201703L	
	cout << "C++ version 20" << endl;
#endif	
	
	Dispatcher dispatcher;
	
	return dispatcher.dispatch(); 
}
