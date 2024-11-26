#pragma once

#include <map>
#include <string>
#include <typeinfo>

#include "../reflect/reflect-main/reflect"
#include "../common/Logger.h"
#include "../controllers/StudentsController.h"

class ObjectMapper;

extern std::map<std::string, ObjectMapper*> mappers;

class ObjectMapper {
	
public:	
	virtual void readInput(void *pV) = 0;
};

template<typename T> class ObjectMapperT : public ObjectMapper
{
public:
	
	void readInput(void *pV) {
		
        // std::string tname = typeid(T).name();

        T t = (*((T*)pV));
        err << "\ntype name: " << reflect::type_name(t) << "\n";

        reflect::for_each([&](auto i) -> void {

            std::string_view typeName = reflect::type_name(reflect::get<i>(t));
            err << "\t" << typeName << "\t";
            err << reflect::member_name<i>(t) << ";\n";

            if (typeName.compare("map") == 0) {

                handleMap(reflect::get<i>(t));

                // using type_name_info = reflect::detail::type_name_info<std::remove_pointer_t<std::remove_cvref_t<member>>>;

                // std::string_view function_name = reflect::detail::function_name<std::remove_pointer_t<std::remove_cvref_t<member>>>();
                // err << "### " << function_name << "\n";

            //     std::string_view qualified_type_name = function_name.substr(type_name_info::begin, function_name.find(type_name_info::end)-type_name_info::begin);
            //     err << "### " << qualified_type_name << "\n";
            }
        }, t);

        // err << tname << "\t";
	}

private:

    template<typename M> void handleMap(M map) {
        using type_name_info = reflect::detail::type_name_info<std::remove_pointer_t<std::remove_cvref_t<M>>>;

        std::string_view function_name = reflect::detail::function_name<std::remove_pointer_t<std::remove_cvref_t<M>>>();
        err << "### " << function_name << "\n";

        std::string_view qualified_type_name = function_name.substr(type_name_info::begin, function_name.find(type_name_info::end)-type_name_info::begin);
        err << "### " << qualified_type_name << "\n";

        // map.size();
        // map[""] = CourseDto<int>();
        //mappers["CourseDto"] -> readInput(&courseDto);
    }

    template<> void handleMap<CourseDto<int>>(CourseDto<int> v) {}
    template<> void handleMap<int>(int v) {}
    template<> void handleMap<std::string>(std::string v) {}
};

