#include <iostream>
#include "Exits.h"
#include "World.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* destination, bool door, direction dir1) :
Entity(name, description), origin(origin), destination(destination), door(door), direction1(dir1)
{
}

Exit::~Exit()
{
}

