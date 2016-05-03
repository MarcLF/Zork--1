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
			Pictures(input);
		}
	}
}

void World::DropObject(MyString&input)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (Item1[i]->taken == true && Item1[i]->name == input && Item1[i]->IsStored == false)
		{
			printf("You drop the %s \n", input);
			Pictures(input);
			Item1[i]->taken = false;
			Item1[i]->place = player->Pos;
		}
		if (Item1[i]->taken == true && Item1[i]->name == input && Item1[i]->IsStored == true)
		{
			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (Item1[i]->place == Item1[j]->place)
				{
					printf("You drop the %s from your %s \n", input, Item1[j]->name);
					Pictures(input);
					Item1[i]->taken = false;
					Item1[i]->place = player->Pos;
					Item1[j]->MaxStorage++;
				}
			}
		}
	}
}

void World::PutObject(MyString&input)
{
	MyString input3;
	char Input3[30];

	printf("\ninto what object?\n\n>");
	gets_s(Input3);
	input3 = Input3;
	printf("\n");

	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (Item1[i]->taken == true && Item1[i]->name == input)
		{
			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (Item1[j]->taken == true && Item1[j]->name == input3 && Item1[j]->CanStore == true && Item1[j]->MaxStorage > 0)
				{
					Item1[i]->IsStored = true;
					Item1[i]->place = Item1[j]->place;
					printf("Now, %s is inside the %s\n", Item1[i]->name.c_str(), Item1[j]->name.c_str());
					Item1[j]->MaxStorage--;
				}
				else if (Item1[j]->taken == true && Item1[j]->name == input3 && Item1[j]->CanStore == true && Item1[j]->MaxStorage == 0)
				{
					printf("%s is full\n", Item1[j]->name.c_str());
				}
				else if (Item1[j]->taken == true && Item1[j]->name == input3 &&  Item1[j]->CanStore == false)
				{
					printf("%s can't store any object\n", Item1[j]->name.c_str());
				}
			}
		}
		else
		{
			printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
			return;
		}
	}
}

void World::Inventory()
{
	MyString input3;
	char Input3[30];
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
		gets_s(Input3);
		input3 = Input3;

		if (input3 == "yes")
		{
			for (int i = 0; i < NUM_ITEMS; i++)
			{
				if (Item1[i]->taken == true)
				{
					if (Item1[i]->IsStored == false)
					{
						printf("\n%s\n", Item1[i]->name);
						printf("%s\n", Item1[i]->description);
					}
					if (Item1[i]->CanStore == true)
					{
						printf("%s have some objects inside it, do you want to know what are those objects?\n", Item1[i]->name);
						gets_s(Input3);
						input3 = Input3;
						if (input3 == "yes")
						{
							for (int j = 0; j < NUM_ITEMS; j++)
							{
								if (Item1[j]->IsStored == true && Item1[i]->name == "bag")
								{
									printf("\n%s\n", Item1[j]->name);
									printf("%s\n", Item1[j]->description);
								}
							}
						}
						else if (input3 == "no")
						{
						}
					}
				}
			}
		}
		else if (input3 == "no")
		{
		}
		else
		{
			printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
		}
	}
	

}