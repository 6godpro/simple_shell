#include "shell.h"


int exec_builtin(char **argv)
{
	char *builtins[] = {"cd", "env", "setenv", "exit", "help", NULL};
	int index = 0;

	while (builtins[index])
	{
		if (_strcmp(argv[0], builtins[index]) == 0)
		{
			switch (index)
			{
				case 0:
					chdir(argv[1]);
				case 1:
					return (1);
				case 2:	
					if (!argv[1] || !argv[2])
					{
						write(STDOUT_FILENO, "usage: setenv variable value\n", 29);
						return (0);
					}

					if (_setenv(argv[1], argv[2]) == -1);
					{
						write(STDERR_FILENO, "failed\n", 7);
						return (0);
					}
					return (1);
				case 3:
					return (_exits(argv[1]));
				case 4:
					return (1);
				default:
					break;
			}
		}
		index++;
	}
	return (-1);
}
