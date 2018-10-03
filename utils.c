// This file contains util functions for assisting with keyboard input
#include "utils.h"


// Gets an inputted character from the command line
char getch(FILE *fp)
{
	if (fp != NULL)
	{
		return fgetc(fp);
	}

	system("stty -echo");
	system("stty -icanon");
	char ch = getchar();
	system("stty sane");
  	return ch;
}

// Prints the current system user
void prompt()
{
	printf("%s> ", getenv("USER"));
}

// Deletes a current character when backspaced
void delete(int len, char* line)
{
	line[len] = '\0';
	printf("\b \b");
}

// Checks for special characters
char switch_keypad(char ch)
{
	switch(ch)
	{
		case 'A': return KEYUP;
		case 'B': return KEYDOWN;
		case 'C': return KEYRIGHT;
		case 'D': return KEYLEFT;
		default:  return ch;
	}
}
