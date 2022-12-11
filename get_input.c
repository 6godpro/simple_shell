#include "shell.h"


char **_getline()
{
	char *line = NULL, **args = NULL;
	size_t n = 0;

	if (getline(&line, &n, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	args = tok_arr(line, " ");

	free(line);

	return (args);
}
