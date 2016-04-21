#include <iostream>
#include "World.h"

void World::TakeObject(MyString&input)
{
	for (int i = 0; i < 3; i++)
	{
		if (Item1[i]->taken == false && Item1[i]->name == input)
		{
			printf("You take the %s \n", input);
			Item1[i]->taken = true;
			Pictures();
		}
	}
}

void World::DropObject(MyString&input)
{
	for (int i = 0; i < 3; i++)
	{
		if (Item1[i]->taken == true && Item1[i]->name == input)
		{
			printf("You drop the %s \n", input);
			Pictures();
			Item1[i]->taken = false;
			Item1[i]->place = player->Pos;
		}
	}
}