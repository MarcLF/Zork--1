#include <iostream>
#include "World.h"

//Look functions
void World::Look()
{
	if (p1->posX == 2 && CashLeft->Cash2 == 0)
	{
		puts(Room1[p1->posX].name);
		printf("You are in a warehouse, in front of you there the table where you took the money");
	}
	else
	{
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
}

void World::LookNorth()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desN);
		}
	}
}

void World::LookSouth()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desS);
		}
	}
}

void World::LookEast()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desE);
		}
	}
}

void World::LookWest()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desW);
		}
	}
}
