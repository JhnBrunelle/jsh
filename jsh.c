#include "jsh.h"

// Main function
int main(int argc, char** argv)
{
	if (argc > 1 && !strcmp(argv[1], SHELL)){
		shell();   // Call the shell
	}

	else
	{
		printf("Error running the SHELL");
	}

	return SUCCESS;
}
