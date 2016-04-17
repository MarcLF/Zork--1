#ifndef _ENTITY_ 
#define _ENTITY_

#include"String.h"

class Entity
{
public:

	MyString name;
	MyString desc;
	Entity(const char* name, const char* desc);
	
	virtual void Look() const{};

};



#endif