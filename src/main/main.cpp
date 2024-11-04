#include <iostream>

#include "../mvc/Dispatcher.h"

using namespace std;
using namespace mvc;

int main(int argc, char **argv)
{
	Dispatcher dispatcher;
	
	return dispatcher.dispatch(); 
}
