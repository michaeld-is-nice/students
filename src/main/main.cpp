#include "../mvc/Dispatcher.h"
#include "../common/Logger.h"

#include "../reflect/reflect-main/reflect"
#include "../mvc/Url.h"

using namespace std;
using namespace mvc;

Logger info(std::cout, " INFO");
Logger err(std::cerr, "ERROR");

int main(int argc, char **argv)
{

	err.enable();

	Dispatcher dispatcher;
	return dispatcher.dispatch(); 
}
