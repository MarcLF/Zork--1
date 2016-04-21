#include <iostream>
#include "World.h"

//Look functions
void World::Look() const
{
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		if (player->Pos == Room1[i])
		{
			printf("%s", Room1[i]->name);
			printf("%s", Room1[i]->description);
		}
	}
	
}

void World::LookNorth() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == Exit1[j]->origin && Exit1[j]->direction1 == north)
		{
			printf("%s", Exit1[j]->description);
			return;
		}
	}
}

void World::LookSouth() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == Exit1[j]->origin && Exit1[j]->direction1 == south)
		{
			printf("%s", Exit1[j]->description);
			return;
		}
	}
}

void World::LookEast() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == Exit1[j]->origin && Exit1[j]->direction1 == east)
		{
			printf("%s", Exit1[j]->description);
			return;
		}
	}
}

void World::LookWest() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == Exit1[j]->origin && Exit1[j]->direction1 == west)
		{
			printf("%s", Exit1[j]->description);
			return;
		}
	}
}
