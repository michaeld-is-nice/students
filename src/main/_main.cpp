//#include <cassert>
//#include <iostream>
//#include <type_traits>
//#include <typeinfo>
//
//#include "../mvc/Dispatcher.h"
//#include "../common/Logger.h"
//
//#include "../reflect/reflect-main/reflect"
//#include "../mvc/Url.h"
//
//using namespace std;
//using namespace mvc;
//
//Logger info(std::cout, " INFO");
//Logger err(std::cerr, "ERROR");


//struct A { int x, y; };
//static_assert(std::is_aggregate_v<A>);
//
//#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
//#define SUM(...)  (sum(NUMARGS(__VA_ARGS__), __VA_ARGS__))
//
//void sum(int numargs, ...) {
//    int     total = 0;
//    va_list ap;
//
//    printf("sum() called with %d params:", numargs);
//    va_start(ap, numargs);
//    while (numargs--)
//        total += va_arg(ap, int);
//    va_end(ap);
//
//    printf(" %d\n", total);
//
//    return;
//}
////
//
//
//template<class Fn, class T> constexpr auto xxx(Fn&& fn, T&&) -> void {
//
//	auto lambda = [&]<auto... Ns>(std::index_sequence<Ns...>) {
//	    (REFLECT_FWD(fn)(std::integral_constant<decltype(Ns), Ns>{}), ...);
//	  };
//
//	lambda(std::make_index_sequence<reflect::size<std::remove_cvref_t<T>>()>{});
//}
//
//template<class A, class B> auto add(A a, B b) -> decltype(a + b) { return a + b; }
//
//
//template<class A, A... as> constexpr auto concat(std::integer_sequence<A, as...> elements) -> std::string {
//
//	std::string result(std::to_string(elements.size()));
//
//	((result = result + std::to_string(as)), ...);
//
//	return result;
//
////	return [](...) -> std::string {
//////
//////		int count = as.size();
//////
//////		va_list ap;
//////		va_start(ap, count);
//////
//////		std::string r;
//////		while (count--)
//////			r += va_arg(ap, A);
//////		va_end(ap);
//////
////		return string();
////	}(As...);
//
//}

//int main(int argc, char **argv)
//{
//#if __cplusplus > 201703L
//	cout << "C++ version 20" << endl;
//#endif

	err.enable();
//	cout << "CCC " << concat(std::integer_sequence<int, 1, 2, 3>{}) << endl;
//
//
//	int result {add(1, 2)};
//	cout << "QQQ " << result << endl;
//
//
////	int j = 2;
//
//	typedef struct _str {int a; string b; string c; } str;
//	auto y = [&]<class T>(T i) -> T { return i; }(reflect::size<std::remove_cvref_t<str>>());
//
//	cout << "YYY " << y << endl;
//
//	cout << "ttt " << sizeof ((int[2]){3, 4}) << endl;
//	SUM(3, 4);
////	(sum((sizeof ((int[2]){3, 4}) / sizeof(int)), 3, 4));
//
//	Dispatcher dispatcher;
//	mvc::Url url(GET, "aaa");
//
////	cout << reflect::type_name(url) << endl;
//
////	typedef struct {int aa; string bb; } str2;
////    typedef struct _str {int a; string b; } str;
////	str s;
////	s.a = 9;
////	s.b = "a";
//    // s.sssss.aa = 15;
//
////	reflect::for_each([&](auto I) -> void {
////
////		string_view sMemberName = reflect::member_name<I>(s);
////        // cout << sMemberName << endl;
////		if (sMemberName.compare("a") == 0) {
////			int offset = reflect::offset_of<I>(s);
////			char * p = ((char *) &s) + offset;
////
////			((int *) p)[0] = 123456789;
////            reflect::get<I>(s) = 5;
////
////            // cout << "value " << reflect::get<I>(s) << endl;
////		}
////		else if (sMemberName.compare("b") == 0) {
////			int offset = reflect::offset_of<I>(s);
////			char * p = ((char *) &s) + offset;
////
////			((string *) p)[0] = "Hello world";
////
////            // cout << "value " << reflect::get<I>(s) << endl;
////		}
//
//
//
//        //cout << "type_name " << reflect::type_name(s) << endl;                  // foo, foo
//        // cout << "member_name " << reflect::member_name<I>(s) << endl;            // a  , b
//       // cout << "type_name " << reflect::type_name(reflect::get<I>(s)) << endl; // int, E
////
//        // string_view typeName = reflect::type_name(reflect::get<I>(s));
//        // if (typeName.compare("str2") == 0) {
//
//// 			int offset = reflect::offset_of<I>(s);
//// 			char * p = ((char *) &s) + offset;
//// 			str2& inner = ((str2 *) p)[0];
//
//// 			reflect::for_each([&](auto I2) -> void {
//
//// //				cout << "inner member_name " << reflect::member_name<I2>(inner) << endl;            // a  , b
//// //				cout << "inner type_name " << reflect::type_name(reflect::get<I2>(inner)) << endl;
//// 			}, inner);
//        // } else
//
//       // cout << "value " << reflect::get<I>(s) << endl;                     // 42 , B
////        cout << "size " << reflect::size_of<I>(s) << endl;                 // 4  , 4
////        cout << "align " << reflect::align_of<I>(s) << endl;                // 4  , 4
////        cout << "offset " << reflect::offset_of<I>(s) << endl;          // 0  , 4
////		cout << endl;
////  }, s);

//	return dispatcher.dispatch();
//}
