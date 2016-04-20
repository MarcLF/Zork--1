#include <iostream>
#include "World.h"

void World::TakeObject(MyString&input)
{
	for (int i = 0; i < 3; i++)
	{
		if (Item1[i]->taken == false && Item1[i]->name == input)
		{
			printf("You take %s \n", input);
			Item1[i]->taken = true;
		}
	}
}

void World::DropObject(MyString&input)
{
	for (int i = 0; i < 3; i++)
	{
		if (Item1[i]->taken == true && Item1[i]->name == input)
		{
			printf("You drop %s \n", input);
			Item1[i]->taken = false;
			Item1[i]->place = player->Pos;
		}
	}
}