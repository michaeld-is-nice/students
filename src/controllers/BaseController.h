#pragma once

#include "../mvc/Url.h"
#include "ControllerException.h"

class BaseController
{
public:
	BaseController() {};
	virtual ~BaseController() {};

	virtual int handleRequest(const mvc::Url url) throw (ControllerException) = 0;
};

