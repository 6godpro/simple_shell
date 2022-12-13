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
int _exits(char *argv)
{
	int i, num = 0;

	if (argv)
	{
		for (i = 0; argv[i]; i++)
		{
			if (argv[i] >= '0' && argv[i] <= '9')
			{
				num = (num * 10) + (argv[i] - '0');
			}
			else
			{
				printf("./shell: Illegal Number: %s\n", argv);
				return (0);
			}
		}
		printf("Goodbye, see you soon!\n");
		exit(num);
	}
	printf("Goodbye, see you soon!\n");
	exit(0);
}
