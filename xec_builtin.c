#include "shell.h"

/**
 * exec_builtin - controls the execution of the
 *		  builtin commands.
 * @argv: array of character pointer to hold
 *	  arguments.
 * Return: If the command is not found - -1.
 */
int exec_builtin(char **argv)
{
	char *builtins[] = {"cd", "env", "setenv", "unsetenv",
				"exit", "alias", "help", NULL};
	int index = 0;

	while (builtins[index])
	{
		if (_strcmp(argv[0], builtins[index]) == 0)
		{
			switch (index)
			{
				case 0:
					chdir(argv[1]);
					return (0);
				case 1:
					print_env();
					return (1);
				case 2:
					return (setenv_handler(argv));
				case 3:
					return (unsetenv_handler(argv));
				case 4:
					return (_exits(argv));
				case 5:
					return (alias_handler(argv));
				case 6:
					return (1);
				default:
					break;
			}
		}
		index++;
	}
	return (-1);
}
