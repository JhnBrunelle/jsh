#include "command.h"
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE_LEN 128
#define NULL 0

// The Tokenizer thatsplits the line by spaces
void tokenizer(char* line, char** args)
{
    int i;
    for (i = 0; i < MAX_LINE_LEN; i++) {

				// Seperate the String
        args[i] = strsep(line, " ");

        if (args[i] == NULL) break;
				if (strlen(args[i]) == 0) i--;

    }
}

// the Execution of the command
short executeCMD(char* line)
{
	int status;
	pid_t pid = fork();			// Fork a new process

	char *args[MAX_LINE_LEN];
	tokenizer(line, args);

	if (pid < 0) {						// Error forking
		perror("fork failed.");
		exit(1);
	} else if (pid == 0){ 		// Child
			// if (strcmp(args[0],"cd")){
			// 	int ret;
			// 	ret = chdir(args[1]);
			// }
			execvp(args[0], args);
	}	else {
		//wait(NULL);
	}

	wait(NULL);

	return status;
}
