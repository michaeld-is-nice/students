#include "StudentsController.h"

#include <iostream>
#include <string>

#include "../mvc/ObjectMapper.h"
#include "../mvc/Url.h"
#include "../common/Logger.h"

using namespace std;

int StudentsController::handleRequest(const mvc::Url url) const {


	if (url.isComply(mvc::PUT, "/students")) {
		
		ObjectMapper<StudentDto> om;
		ObjectMapper<CourseDto<int>> om2;

		StudentDto studentDto;
		om.readInput(studentDto);
		err << studentDto.firstName;

		CourseDto<int> courseDto;
		om2.readInput(courseDto);
		err << courseDto.firstName;


		return handleCreateStudent(studentDto);
	}
	
	return 200;
}

int StudentsController::handleCreateStudent(const StudentDto& dto) const {
	
	
	return 200;
}
