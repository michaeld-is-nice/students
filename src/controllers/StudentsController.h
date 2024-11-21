#pragma once

#include "BaseController.h"

#include <string>

template<typename T> struct CourseDto {
	std::string fieldOfStudy;
	T whatever;
};

typedef struct {
	std::string firstName; 
	std::string lastName; 
	int birthYear;
	CourseDto<int> course;
} StudentDto;


class StudentsController : public BaseController
{
	
	int handleCreateStudent(StudentDto&);
	
public:
	
	virtual int handleRequest(const mvc::Url url);
};

