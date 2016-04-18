#include <iostream>
#include "World.h"

void World::Maze() //This function represents a minigame for the player which he will be trapped in the maze until he finds the exit
{
	MyString input;
	int cont = 0;
	char Maze[30] = "You are still in the Maze";
	char Input[30];

	while (cont < 5) //Until Cont reach 5 the player won't be able to get out of the Maze
	{
		printf("\n>");
		gets_s(Input);
		input = Input;

		//Movement inputs
		if (input == "go north" || input == "north" || input == "go n" || input == "n")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if(input == "go west" || input == "west" || input == "go w" || input == "w")
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if (input == "go south" || input == "south" || input == "go s" || input == "s")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if (input == "go east" || input == "east" || input == "go e" || input == "e")
			{
				puts(Maze);
				cont++;
			}
			else if (input == "go west" || input == "west" || input == "go w" || input == "w")
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if(input == "go east" || input == "east" || input == "go e" || input == "e")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if (input == "go north" || input == "north" || input == "go n" || input == "n")
			{
				puts(Maze);
				cont++;
			}
			else
			{
				puts(Maze);
			}
		}
		else if (input == "go west" || input == "west" || input == "go w" || input == "w")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);

			if (input == "go north" || input == "north" || input == "go n" || input == "n")
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
		else if (input == "exit")
		{
			exit(0);
		}
	}

	printf("\nFINALLY after so much effort you get to find the exit of this goddanm Maze.\n\n");

	player->posX = 12; //It redirects the player back into the road
	printf("%s", Room1[player->posX]->name);
	printf("%s", Room1[player->posX]->desc);
}
