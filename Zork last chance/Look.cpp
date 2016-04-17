#include <iostream>
#include "World.h"

//Look functions
void World::Look() const
{
	if (player->posX == 2 && CashLeft->Cash2 == 0)
	{
		printf("%s", Room1[player->posX]->name);
		printf("You are in a warehouse, in front of you there the table where you took the money");
	}
	else
	{
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
}

void World::LookNorth() const
{
	for (int j = 0; j < 13; j++)
	{
		if (player->posX == j)
		{
			puts(Exit1[player->posX].desN);
		}
	}
}

void World::LookSouth() const
{
	for (int j = 0; j < 13; j++)
	{
		if (player->posX == j)
		{
			puts(Exit1[player->posX].desS);
		}
	}
}

void World::LookEast() const
{
	for (int j = 0; j < 13; j++)
	{
		if (player->posX == j)
		{
			puts(Exit1[player->posX].desE);
		}
	}
}

void World::LookWest() const
{
	for (int j = 0; j < 13; j++)
	{
		if (player->posX == j)
		{
			puts(Exit1[player->posX].desW);
		}
	}
}
