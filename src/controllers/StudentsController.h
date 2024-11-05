#pragma once

#include "BaseController.h"

class StudentsController : public BaseController
{
public:
	
	virtual int handleRequest(const mvc::Url url) throw (ControllerException);
};

