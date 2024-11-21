#include "StudentsController.h"

#include <iostream>
#include <string>

#include "../mvc/ObjectMapper.h"
#include "../mvc/Url.h"
#include "../common/Initializer.h"

using namespace std;

static Initializer init([]() -> void {
	mappers["StudentDto"] = new ObjectMapperT<StudentDto>();
	mappers["CourseDto"] = new ObjectMapperT<CourseDto<string>>();
});

int StudentsController::handleRequest(const mvc::Url url) {

	if (url.isComply(mvc::PUT, "/student")) {
		
		StudentDto studentDto;
		CourseDto<string> courseDto;
		mappers["StudentDto"] -> readInput(&studentDto);
		mappers["CourseDto"] -> readInput(&courseDto);
		
		return handleCreateStudent(studentDto);
	}
	
	return 200;
}

int StudentsController::handleCreateStudent(StudentDto&) {
	
//	string s;
//	
//	cin >> s;
//	
//	cout << "{" << s << "}";
	
	return 200;
}
