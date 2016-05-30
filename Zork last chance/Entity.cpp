#include"Entity.h"

Entity::Entity(const char* name, const char *description, Type entities) :name(name), description(description), entities(entities)
{
}

Entity::~Entity()
{
}