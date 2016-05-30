#include <iostream>
#include "World.h"

//Look functions
void World::Look() const
{
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		if (player->Pos == (Room*)entity[i])
		{
			printf("%s", ((Room*)entity[i])->name);
			printf("%s", ((Room*)entity[i])->description);
		}
	}
	
}

void World::LookNorth() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == ((Exit*)entity[j])->origin && ((Exit*)entity[j])->direction1 == north)
		{
			printf("%s", ((Exit*)entity[j])->description);
			return;
		}
	}
}

void World::LookSouth() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == ((Exit*)entity[j])->origin && ((Exit*)entity[j])->direction1 == south)
		{
			printf("%s", ((Exit*)entity[j])->description);
			return;
		}
	}
}

void World::LookEast() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == ((Exit*)entity[j])->origin && ((Exit*)entity[j])->direction1 == east)
		{
			printf("%s", ((Exit*)entity[j])->description);
			return;
		}
	}
}

void World::LookWest() const
{
	for (int j = 0; j < NUM_EXITS; j++)
	{
		if (player->Pos == ((Exit*)entity[j])->origin && ((Exit*)entity[j])->direction1 == west)
		{
			printf("%s", ((Exit*)entity[j])->description);
			return;
		}
	}
}
