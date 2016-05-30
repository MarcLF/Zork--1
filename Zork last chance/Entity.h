#ifndef _Entity_ 
#define _Entity_

#include"String.h"

enum Type
{
	ROOM,
	EXIT,
	ITEM,
	PLAYER
};

class Entity
{
public:
	MyString name;
	MyString description;

	Type entities;

	Entity(const char* name, const char* description, Type);
	~Entity();
};

#endif