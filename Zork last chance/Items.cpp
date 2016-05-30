#include "Items.h"

Item::Item(const char* name, const char* description, Room* room, bool CanStore, bool IsStored, int MaxStorage, Type item) : 
Entity(name, description, item), place(room), CanStore(CanStore), IsStored(IsStored), MaxStorage(MaxStorage)
{
}

Item::~Item()
{
}

