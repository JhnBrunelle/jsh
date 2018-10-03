#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_BUFFER 1024

#define TERMINATE -1
#define FAILURE 1
#define SUCCESS 0

#define FALSE 0
#define TRUE 1
#define DELETE 127
#define KEYLEFT 4
#define KEYRIGHT 5
#define KEYUP 3
#define KEYDOWN 2

void prompt();
char getch(FILE*);
void delete(int, char*);
char switch_keypad(char);

#endif
