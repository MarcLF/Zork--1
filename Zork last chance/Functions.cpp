#include <iostream>
#include "World.h"

void World::TakeObject(MyString&input)
{
	for (int i = 0; i < NUM_ITEMS; i++)
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
	for (int i = 0; i < NUM_ITEMS; i++)
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

void World::Inventory()
{
	char Input[10];
	MyString input;
	int t = 0;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (Item1[i]->taken == true)
		{
			t++;
		}
	}
	printf("You have a total of %d items in your inventory\n", t);

	if (t > 0)
	{
		printf("Do you wish to know each name and description of every item?\n\n>");
		gets_s(Input);
		input = Input;

		if (input == "yes")
		{
			for (int i = 0; i < NUM_ITEMS; i++)
			{
				if (Item1[i]->taken == true)
				{
					printf("\n%s\n", Item1[i]->name);
					printf("%s\n", Item1[i]->description);
				}
			}
		}
		else if (input == "no")
		{
		}
		else
		{
			printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
		}
	}
	

}