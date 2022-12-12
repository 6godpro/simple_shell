#include "shell.h"

/**
 * free_args - frees argument vector.
 * @argv: argument vector to be freed.
 */
void free_args(char **argv)
{
	int index;

	for (index = 0; argv[index]; index++)
		free(argv[index]);

	free(argv);
}
