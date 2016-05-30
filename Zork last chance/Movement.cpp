#include <iostream>
#include "World.h"

//Movement functions
void World::GoNorth()
{
	if (player->Pos == (Room*)entity[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < NUM_EXITS; i++)
		{
			if (entity[i]->entities == EXIT && ((Exit*)entity[i])->origin == player->Pos && ((Exit*)entity[i])->direction1 == north)
			{
				for (int j = 0; j < NUM_ROOMS; j++)
				{
					if (((Exit*)entity[i])->destination == (Room*)entity[j])
					{
						if (((Exit*)entity[i])->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else if (((Exit*)entity[i])->door == false)
						{
							player->Pos = ((Exit*)entity[i])->destination;
							printf("%s", ((Room*)entity[j])->name);
							printf("%s", ((Room*)entity[j])->description);
							return;
						}
					}
				}
			}
		}
		printf("You can't go that way. \n");
	}
}

void World::GoSouth()
{
	if (player->Pos == (Room*)entity[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < NUM_EXITS; i++)
		{
			if (entity[i]->entities == EXIT && ((Exit*)entity[i])->origin == player->Pos && ((Exit*)entity[i])->direction1 == south)
			{
				for (int j = 0; j < NUM_ROOMS; j++)
				{
					if (((Exit*)entity[i])->destination == (Room*)entity[j])
					{
						if (((Exit*)entity[i])->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else if (((Exit*)entity[i])->door == false)
						{
							player->Pos = ((Exit*)entity[i])->destination;
							printf("%s", ((Room*)entity[j])->name);
							printf("%s", ((Room*)entity[j])->description);
							return;
						}
					}
				}
			}
		}
		printf("You can't go that way. \n");
	}
}

void World::GoEast()
{
	if (player->Pos == (Room*)entity[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < NUM_EXITS; i++)
		{
			if (entity[i]->entities == EXIT && ((Exit*)entity[i])->origin == player->Pos && ((Exit*)entity[i])->direction1 == east)
			{
				for (int j = 0; j < NUM_ROOMS; j++)
				{
					if (((Exit*)entity[i])->destination == (Room*)entity[j])
					{
						if (((Exit*)entity[i])->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else if (((Exit*)entity[i])->door == false)
						{
							player->Pos = ((Exit*)entity[i])->destination;
							printf("%s", ((Room*)entity[j])->name);
							printf("%s", ((Room*)entity[j])->description);
							return;
						}
					}
				}
			}
		}
		printf("You can't go that way. \n");
	}
}

void World::GoWest()
{
	if (player->Pos == (Room*)entity[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < NUM_EXITS; i++)
		{
			if (entity[i]->entities == EXIT && ((Exit*)entity[i])->origin == player->Pos && ((Exit*)entity[i])->direction1 == west)
			{
				for (int j = 0; j < NUM_ROOMS; j++)
				{
					if (((Exit*)entity[i])->destination == (Room*)entity[j])
					{
						if (((Exit*)entity[i])->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else if (((Exit*)entity[i])->door == false)
						{
							player->Pos = ((Exit*)entity[i])->destination;
							printf("%s", ((Room*)entity[j])->name);
							printf("%s", ((Room*)entity[j])->description);
							return;
						}
					}
				}
			}
		}
		printf("You can't go that way. \n");
	}
}