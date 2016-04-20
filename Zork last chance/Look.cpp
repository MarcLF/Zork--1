#include <iostream>
#include "World.h"

//Look functions
void World::Look() const
{
	/*if (player->posX == 2 && Item1[0]->taken == true)
	{
		printf("%s", Room1[player->posX]->name);
		printf("You are in a warehouse, in front of you there the table where you took the money");
	}
	else
	{
		printf("%s", Room1[player->Pos]->name);
		printf("%s", Room1[player->posX]->description);
	}*/
}

void World::LookNorth() const
{
	for (int j = 0; j < 26; j++)
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
	for (int j = 0; j < 26; j++)
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
	for (int j = 0; j < 26; j++)
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
	for (int j = 0; j < 26; j++)
	{
		if (player->Pos == Exit1[j]->origin && Exit1[j]->direction1 == west)
		{
			printf("%s", Exit1[j]->description);
			return;
		}
	}
}
