#include <iostream>
#include "World.h"

void World::TakeObject(MyString&input)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (((Item*)entity[i])->taken == false && ((Item*)entity[i])->name == input)
		{
			printf("You take the %s \n", input);
			((Item*)entity[i])->taken = true;
			Pictures(input);
		}
	}
}

void World::DropObject(MyString&input)
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (((Item*)entity[i])->taken == true && ((Item*)entity[i])->name == input && ((Item*)entity[i])->IsStored == false)
		{
			printf("You drop the %s \n", input);
			Pictures(input);
			((Item*)entity[i])->taken = false;
			((Item*)entity[i])->place = player->Pos;
		}
		if (((Item*)entity[i])->taken == true && ((Item*)entity[i])->name == input && ((Item*)entity[i])->IsStored == true)
		{
			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (((Item*)entity[i])->place == ((Item*)entity[j])->place)
				{
					printf("You drop the %s from your %s \n", input, ((Item*)entity[j])->name);
					Pictures(input);
					((Item*)entity[i])->taken = false;
					((Item*)entity[i])->place = player->Pos;
					((Item*)entity[j])->MaxStorage++;
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
		if (((Item*)entity[i])->taken == true && ((Item*)entity[i])->name == input)
		{
			for (int j = 0; j < NUM_ITEMS; j++)
			{
				if (((Item*)entity[j])->taken == true && ((Item*)entity[j])->name == input3 && ((Item*)entity[j])->CanStore == true && ((Item*)entity[j])->MaxStorage > 0)
				{
					((Item*)entity[i])->IsStored = true;
					((Item*)entity[i])->place = ((Item*)entity[j])->place;
					printf("Now, %s is inside the %s\n", ((Item*)entity[i])->name.c_str(), ((Item*)entity[j])->name.c_str());
					((Item*)entity[j])->MaxStorage--;
					return;
				}
				else if (((Item*)entity[j])->taken == true && ((Item*)entity[j])->name == input3 && ((Item*)entity[j])->CanStore == true && ((Item*)entity[j])->MaxStorage == 0)
				{
					printf("%s is full\n", ((Item*)entity[j])->name.c_str());
					return;
				}
				else if (((Item*)entity[j])->taken == true && ((Item*)entity[j])->name == input3 && ((Item*)entity[j])->CanStore == false)
				{
					printf("%s can't store any object\n", ((Item*)entity[j])->name.c_str());
					return;
				}
			}
		}
	}
	printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
}

void World::Inventory()
{
	MyString input3;
	char Input3[30];
	int t = 0;
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		if (((Item*)entity[i])->taken == true)
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
		printf("\n");

		if (input3 == "yes")
		{
			for (int i = 0; i < NUM_ITEMS; i++)
			{
				if (((Item*)entity[i])->taken == true)
				{
					if (((Item*)entity[i])->IsStored == false)
					{
						printf("\n%s\n", ((Item*)entity[i])->name);
						printf("%s\n", ((Item*)entity[i])->description);
					}
					if (((Item*)entity[i])->CanStore == true && ((Item*)entity[i])->MaxStorage < 3)
					{
						printf("%s have some objects inside it, do you want to know what are those objects?\n\n>", ((Item*)entity[i])->name);
						gets_s(Input3);
						input3 = Input3;
						if (input3 == "yes")
						{
							for (int j = 0; j < NUM_ITEMS; j++)
							{
								if (((Item*)entity[j])->IsStored == true && ((Item*)entity[i])->name == "bag")
								{
									printf("\n%s\n", ((Item*)entity[j])->name);
									printf("%s\n", ((Item*)entity[j])->description);
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