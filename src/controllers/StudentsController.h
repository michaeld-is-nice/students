#pragma once

#include <string>
#include <map>

#include "BaseController.h"

template<typename T> struct CourseDto {
	std::string fieldOfStudy;
	T whatever;
};

typedef struct {
	std::string firstName; 
	std::string lastName; 
	int birthYear;
	CourseDto<int> course;
    std::map<std::string, CourseDto<int> > coursesMap;
} StudentDto;


class StudentsController : public BaseController
{
	
	int handleCreateStudent(StudentDto&);
	
public:
	
	virtual int handleRequest(const mvc::Url url);
};

