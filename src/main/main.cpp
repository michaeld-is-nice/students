#include <iostream>

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
//#if __cplusplus > 201703L	
//	cout << "C++ version 20" << endl;
//#endif	

	err.enable();
	
	Dispatcher dispatcher;
	mvc::Url url(GET, "aaa");
	
//	cout << reflect::type_name(url) << endl;
	
	typedef struct {int aa; string bb; } str2;
    typedef struct _str {int a; string b; } str;
	str s;
	s.a = 9;
	s.b = "a";
    // s.sssss.aa = 15;
	
	reflect::for_each([&](auto I) -> void {
    
		string_view sMemberName = reflect::member_name<I>(s);
        // cout << sMemberName << endl;
		if (sMemberName.compare("a") == 0) {
			int offset = reflect::offset_of<I>(s);
			char * p = ((char *) &s) + offset;
			
			((int *) p)[0] = 123456789;
            reflect::get<I>(s) = 5;

            // cout << "value " << reflect::get<I>(s) << endl;
		} 
		else if (sMemberName.compare("b") == 0) {
			int offset = reflect::offset_of<I>(s);
			char * p = ((char *) &s) + offset;
			
			((string *) p)[0] = "Hello world";

            // cout << "value " << reflect::get<I>(s) << endl;
		}


		
        //cout << "type_name " << reflect::type_name(s) << endl;                  // foo, foo
        // cout << "member_name " << reflect::member_name<I>(s) << endl;            // a  , b
       // cout << "type_name " << reflect::type_name(reflect::get<I>(s)) << endl; // int, E
//		
        // string_view typeName = reflect::type_name(reflect::get<I>(s));
        // if (typeName.compare("str2") == 0) {
			
// 			int offset = reflect::offset_of<I>(s);
// 			char * p = ((char *) &s) + offset;
// 			str2& inner = ((str2 *) p)[0];
			
// 			reflect::for_each([&](auto I2) -> void {
			
// //				cout << "inner member_name " << reflect::member_name<I2>(inner) << endl;            // a  , b
// //				cout << "inner type_name " << reflect::type_name(reflect::get<I2>(inner)) << endl;
// 			}, inner);
        // } else
		
       // cout << "value " << reflect::get<I>(s) << endl;                     // 42 , B
//        cout << "size " << reflect::size_of<I>(s) << endl;                 // 4  , 4
//        cout << "align " << reflect::align_of<I>(s) << endl;                // 4  , 4
//        cout << "offset " << reflect::offset_of<I>(s) << endl;          // 0  , 4
		cout << endl;
  }, s);
	
	return dispatcher.dispatch(); 
}
