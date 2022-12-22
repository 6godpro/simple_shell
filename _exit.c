#include "shell.h"

/**
 * _exits - handles arguments for exit command.
 * @argv: argument for exit command.
 *
 * Return: 0 - if an illegal number is passed.
 * Description: program will exit with the value
 *		passed as argument provided it is
 *		not an invalid number. It termin-
 *		ates with zero if no argument was
 *		passed.
 */
int _exits(char **argv)
{
	int i, num = 0;
	char *error_msg = "./hsh: 1: exit: Illegal Number:";

	if (argv[1])
	{
		for (i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				num = (num * 10) + (argv[1][i] - '0');
			}
			else
			{
				write(STDERR_FILENO, error_msg, _strlen(error_msg));
				write(STDERR_FILENO, argv[1], _strlen(argv[1]));
				write(STDERR_FILENO, "\n", 1);

				return (2);
			}
		}
		free_args(argv);
		exit(num);
	}
	free_args(argv);
	exit(num);
}
