#include <iostream>
#include "World.h"

void World::Maze() //This function represents a minigame for the player which he will be trapped in the maze until he finds the exit
{
	MyString input;
	int cont = 0;
	char Maze[30] = "\nYou are still in the Maze.";
	char Input[30];

	while (cont < 5) //Until Cont reach 5 the player won't be able to get out of the Maze
	{
		printf("\n>");
		gets_s(Input);
		input = Input;

		if (cont == 2)
		{
			printf("After a couple hours walking in circles you find yourself in a small glade, standing in the middle you see an old rusty key.\n");
			printf("\n>");
			gets_s(Input);
			input = Input;

		if (input == "take")
		{
			printf("What item?\n\n>");
			gets_s(Input);
			input = Input;

			for (int i = 0; i < 3; i++)
			{
				if (Item1[i]->taken == false && Item1[i]->name == input)
				{
					TakeObject(input);
				}
				else if (Item1[i]->taken == true && Item1[i]->name == input)
				{
					printf("there is no %s to take \n", input);
				}
			}
		}
			cont++;
		}
		else 
		{
			//Movement inputs
		if (input == "go north" || input == "north" || input == "go n" || input == "n")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);
			input = Input;

			if (input == "go west" || input == "west" || input == "go w" || input == "w")
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
			input = Input;

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
		else if (input == "go east" || input == "east" || input == "go e" || input == "e")
		{
			puts(Maze);
			printf("\n>");
			gets_s(Input);
			input = Input;

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
			input = Input;

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
	}

	printf("\nFINALLY after so much effort you get to find the exit of this goddanm Maze.\n\n");

	player->Pos = Room1[12]; //It redirects the player back into the road
	printf("%s", Room1[12]->name);
	printf("%s", Room1[12]->description);
}
