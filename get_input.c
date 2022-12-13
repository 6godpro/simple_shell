#include "shell.h"

/**
 * get_input - Gets line and tokenizes it.
 * @len: Pointer to hold the return value of
 *	 getline function.
 * Return: NULL - if getline fails.
 *	   O/w - the tokenized strings.
 */
char **get_input(ssize_t *len)
{
	char *line = NULL, **args = NULL;
	size_t n = 0;

	*len = getline(&line, &n, stdin);
	if (*len == -1)
	{
		free(line);
		return (NULL);
	}
	args = tok_arr(line, " ");

	free(line);

	return (args);
}
