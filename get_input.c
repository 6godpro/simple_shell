#include "shell.h"


char **get_input(ssize_t *len)
{
	char *line = NULL, **args = NULL;
	size_t n = 0;

	if ((*len = getline(&line, &n, stdin)) == -1)
	{
		free(line);
		return (NULL);
	}
	args = tok_arr(line, " ");

	free(line);

	return (args);
}
