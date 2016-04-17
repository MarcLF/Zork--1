#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "World.h"
#include "String.h"
#include "Vector.h"
#include "Welcome Screen.h"
#include <cstdlib>//Necessary for system("MODE CON COLS=100 LINES=60")

int main()
{
	World scenary;
	Welcome screen;
	MyString input;

	char Input[30];

	system("MODE CON COLS=100 LINES=55");//I used this command so the whole image fit into the screen
	scenary.CreateWorld();
	scenary.Exits();

	screen.WelcomeScreen();//Welcome screen image

	printf("Press any key to continue");
	_getch();
	system("cls");

	printf("--Welcome to Zork: Last Chance--\n\n");
	puts(scenary.Room1[0].name);
	puts(scenary.Room1[0].desc);

	while (1)
	{
		printf("\n>");
		gets_s(Input);
		input = Input;
		scenary.GetInput(input);
	}

	system("pause");
	return 0;
}