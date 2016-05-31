#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "World.h"
#include "String.h"
#include "Vector.h"
#include "Welcome Screen.h"
#include "MemoryLeaks.h"
#include <Windows.h>
#include <conio.h>
#include <cstdlib>//Necessary for system("MODE CON COLS=100 LINES=60")

#define Buffer 50

int main()
{
	World scenary;
	Welcome screen;
	MyString input;

	/* -- Time -- */
	uint initialization_t = 0;
	uint current_t = 0;
	uint size = 0;
	initialization_t = GetTickCount();
	/* --  --  -- */

	char order = 0;
	char Input[Buffer];

	system("MODE CON COLS=100 LINES=55");//I used this command so the whole image fit into the screen
	scenary.CreateWorld();

	screen.WelcomeScreen();//Welcome screen image

	printf("Press any key to continue");
	_getch();
	system("cls");

	printf("--Welcome to Zork: Last Chance--\n\n");
	printf("Start\n");
	printf("You see a big sign which says WELCOME to the COWARD CITY!Where all cowards come to hide from the rest of the world!There is a bag on the floor\n");

	while (1)
	{
		current_t = GetTickCount();

		if (_kbhit())
		{
			if (size < Buffer)
			{
				order = _getch();
				Input[size++] = order;
				printf("%c", order);

				if (Input[size - 1] == '\b')
				{
					if (size > 0)
					{
						size -= 2;
					}
				}
				if (Input[size - 1] == '\r')
				{
					printf("\n");
					Input[size - 1] = '\0';
					size = 0;
					input = Input;
					scenary.Input(input);
				}
			}
		}
	}

	system("pause");
	return 0;
}