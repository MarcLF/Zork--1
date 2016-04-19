#include "Items.h"

Item::Item(const char* name, const char* description, Room* room) : Entity(name, description), place(room)
{
}

Item::~Item()
{
}

