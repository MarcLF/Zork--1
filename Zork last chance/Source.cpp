#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "World.h"
#include "String.h"
#include "Vector.h"
#include "Welcome Screen.h"
#include "MemoryLeaks.h"
#include <cstdlib>//Necessary for system("MODE CON COLS=100 LINES=60")

int main()
{
	World scenary;
	Welcome screen;
	MyString input;

	char Input[30];

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
		printf("\n>");
		gets_s(Input);
		printf("\n");
		input = Input;
		scenary.Input(input);
	}

	system("pause");
	return 0;
}