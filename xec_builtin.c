#include "shell.h"


int exec_builtin(char **argv)
{
	char *builtins[] = {"cd", "env", "exit", "help", NULL};
	int index = 0;

	while (builtins[index])
	{
		if (strcmp(argv[0], builtins[index]) == 0)
		{
			switch(index)
			{
				case 0:
					chdir(argv[1]);
				case 1:
					return (1);
				case 2:
					return (1);
				case 3:
					exit (1);
				default:
					break;
			}
		}
		index++;
	}
	return (-1);
}
