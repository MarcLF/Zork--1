#include <iostream>
#include "Exits.h"
#include "World.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, bool door, direction dir1, Type exit) :
Entity(name, description, exit), origin(origin), destination(destination), door(door), direction1(dir1)
{
}

Exit::~Exit()
{
}

