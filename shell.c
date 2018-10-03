
#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>



void shell(void)
{

	int status = 0;          // Status of shell
  int len = 0;             // Current line length
  short specChar = FALSE;  // Bool if character is a special key
  FILE *fp = NULL;

  // Allocate sapce for the line
	char ch, *line = (char*)malloc(MAX_LINE_BUFFER);

  // Main shell Loop
	prompt();
	while(TRUE)
	{

    // Get the current char and check if it's a special character
		ch = getch(fp);
		if (specChar){
			specChar = FALSE;
			ch = switch_keypad(ch);
		}

		switch(ch){

      // Arrow keys
			case '\033':
				getch(NULL);
				specChar = TRUE;
				continue;
				break;

      // Don't save tabs or spaces
			case KEYLEFT:
			case KEYRIGHT:
			case KEYUP:
			case KEYDOWN:
			case '\t':
				break;

      // Backspacing
			case DELETE:
			{
				if (len > 0)
					delete(--len, line);
				break;
			}

			default:
			{
				if (len < MAX_LINE_BUFFER){


					if (ch != '\n'){
						printf("%c", ch);
						line[len++] = ch;

					} else if (ch == '\n' && len > 0){     // Enter!
						printf("%c", ch);
						line[len] = '\0';
						status = executeCMD(line);      // send line to be executed in command.c

						free(line);     // Free the line space

						if (status == TERMINATE) exit(SUCCESS);   // If we terminate the app

						line = (char*)malloc(MAX_LINE_BUFFER);    // Allocate new Line Space
						len = 0;

						prompt();   // New Prompt for User
					}
				}
				break;
			}
		}
	}

	fclose(fp);
}
