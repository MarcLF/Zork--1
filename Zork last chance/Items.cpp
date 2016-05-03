#include "Items.h"

Item::Item(const char* name, const char* description, Room* room, bool CanStore, bool IsStored) : Entity(name, description), place(room), CanStore(CanStore), IsStored(IsStored)
{
}

Item::~Item()
{
}

