#ifndef _Entity_ 
#define _Entity_

#include"String.h"

class Entity
{
public:
	MyString name;
	MyString description;

	Entity(const char* name, const char* description);
	~Entity();
};

#endif