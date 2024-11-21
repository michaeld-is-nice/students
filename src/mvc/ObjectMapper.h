#pragma once

#include <map>
#include <string>
#include <typeinfo>

#include "../reflect/reflect-main/reflect"
#include "../common/Logger.h"

class ObjectMapper {
	
public:	
	virtual void readInput(void *pV) = 0;
};

template<typename T> class ObjectMapperT : public ObjectMapper
{
public:
	
	void readInput(void *pV) {
		
		std::string tname = typeid(T).name();
		
		err << reflect::type_name(*((T*)pV));
//		err << tname;
	}
};

extern std::map<std::string, ObjectMapper*> mappers;

