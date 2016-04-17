#include <iostream>
#include "World.h"

#define EQUAL 0

void World::Maze() //This function represents a minigame for the player which he will be trapped in the maze until he finds the exit
{
	int cont = 0;
	char Maze[30] = "You are still in the Maze";
	char Input[30];

	while (cont < 5) //Until Cont reach 5 the player won't be able to get out of the Maze
	{
		printf("\n>");
		gets_s(Input);

		//Movement inputs
		if ((strcmp("go north", Input) == EQUAL) || (strcmp("north", Input) == EQUAL) || (strcmp("go n", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if ((strcmp("go west", Input) == EQUAL) || (strcmp("west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL) || (strcmp("w", Input) == EQUAL))
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if ((strcmp("go south", Input) == EQUAL) || (strcmp("south", Input) == EQUAL) || (strcmp("go s", Input) == EQUAL) || (strcmp("s", Input) == EQUAL))
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if ((strcmp("go east", Input) == EQUAL) || (strcmp("east", Input) == EQUAL) || (strcmp("go e", Input) == EQUAL) || (strcmp("east", Input) == EQUAL))
			{
				puts(Maze);
				cont++;
			}
			else if ((strcmp("go west", Input) == EQUAL) || (strcmp("west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL) || (strcmp("west", Input) == EQUAL))
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if ((strcmp("go east", Input) == EQUAL) || (strcmp("east", Input) == EQUAL) || (strcmp("go e", Input) == EQUAL) || (strcmp("e", Input) == EQUAL))
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if ((strcmp("go north", Input) == EQUAL) || (strcmp("north", Input) == EQUAL) || (strcmp("go north", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if ((strcmp("go west", Input) == EQUAL) || (strcmp("west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL) || (strcmp("w", Input) == EQUAL))
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if ((strcmp("go north", Input) == EQUAL) || (strcmp("north", Input) == EQUAL) || (strcmp("go n", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}

		//Various
		else if (strcmp("exit", Input) == EQUAL || strcmp("quit", Input) == EQUAL)//strcmp returns 0 if both strings are the same
		{
			exit(0);
		}
	}

	printf("\nFINALLY after so much effort you get to find the exit of this goddanm Maze.\n\n");

	player->posX = 12; //It redirects the player back into the road
	printf("%s", Room1[player->posX]->name);
	printf("%s", Room1[player->posX]->desc);
}
