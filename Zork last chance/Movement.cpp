#include <iostream>
#include "World.h"

//Movement functions
void World::GoNorth()
{
	if (player->Pos == Room1[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < 29; i++)
		{
			if (Exit1[i]->origin == player->Pos && Exit1[i]->direction1 == north)
			{
				for (int j = 0; j < 14; j++)
				{
					if (Exit1[i]->destination == Room1[j])
					{
						if (Exit1[i]->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else
						{
							player->Pos = Exit1[i]->destination;
							printf("%s", Room1[j]->name);
							printf("%s", Room1[j]->description);
							return;
						}
					}
				}
			}
		}
	}
}

void World::GoSouth()
{
	if (player->Pos == Room1[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < 29; i++)
		{
			if (Exit1[i]->origin == player->Pos && Exit1[i]->direction1 == south)
			{
				for (int j = 0; j < 14; j++)
				{
					if (Exit1[i]->destination == Room1[j])
					{
						if (Exit1[i]->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else
						{
							player->Pos = Exit1[i]->destination;
							printf("%s", Room1[j]->name);
							printf("%s", Room1[j]->description);
							return;
						}
					}
				}
			}
		}
	}
}

void World::GoEast()
{
	if (player->Pos == Room1[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < 29; i++)
		{
			if (Exit1[i]->origin == player->Pos && Exit1[i]->direction1 == east)
			{
				for (int j = 0; j < 14; j++)
				{
					if (Exit1[i]->destination == Room1[j])
					{
						if (Exit1[i]->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else
						{
							player->Pos = Exit1[i]->destination;
							printf("%s", Room1[j]->name);
							printf("%s", Room1[j]->description);
							return;
						}
					}
				}
			}
		}
	}
}

void World::GoWest()
{
	if (player->Pos == Room1[13])
	{
		printf("You are still in the Maze \n");
		Maze();
	}
	else
	{
		for (int i = 0; i < 29; i++)
		{
			if (Exit1[i]->origin == player->Pos && Exit1[i]->direction1 == west)
			{
				for (int j = 0; j < 14; j++)
				{
					if (Exit1[i]->destination == Room1[j])
					{
						if (Exit1[i]->door == true)
						{
							printf("There is a locked door here. \n");
							return;
						}
						else
						{
							player->Pos = Exit1[i]->destination;
							printf("%s", Room1[j]->name);
							printf("%s", Room1[j]->description);
							return;
						}
					}
				}
			}
		}
	}
}