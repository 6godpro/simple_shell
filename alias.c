#include "shell.h"


char **creat_alias(void);
int set_alias(char **aliases, char **argv);

/**
 * creat_alias - allocates memory for the first alias.
 *
 * Return: 0 on success, -1 on error.
 */
char **creat_alias(void)
{
	char **memory;

	memory = malloc(sizeof(char *) * 2);
	if (memory)
		return (NULL);

	memory[0] = "x";
	memory[1] = NULL;

	return (memory);
}
/**
 * set_alias - Creates a new alias or updates an existing one.
 * @argv: Array of character pointer.
 * @aliases: ...
 * Return: 0 on success, -1 on error.
 */
int set_alias(char **aliases, char **argv)
{
	int len = 0, index = 0;
	int i, j;
	char **tmp, *new;
	static int flag;

	if (!flag)
	{
		aliases = creat_alias();
		if (aliases == NULL)
			return (-1);
		flag = 1;
	}
	printf("%s\n", aliases[0]);
	for (i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] == '\'' || argv[i][j] == '\"')
			{
				argv[i][j] = '\'';
				continue;
			}
			if (argv[i][j + 1] == '\0')
				len++;
			len++;
		}
	}
	new = malloc(len + 3);
	if (!new)
	{
		free(aliases);
		return (-1);
	}

	for (i = 1; argv[i]; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j - 1] == '=' && argv[i][j] != '\'')
			{
				new[index] = '\'';
				index++;
			}

			new[index] = argv[i][j];
			index++;
			if (argv[i][j + 1] == '\0' && argv[i + 1] != NULL)
			{
				new[index] = ' ';
				index++;
			}
		}
	}
	if (new[index - 1] != '\'')
		new[index] = '\'';
	new[index + 1] = '\0';

	for (i = 0, len = 0; argv[1][i] != '='; i++)
		len++;

	for (i = 0; aliases[i]; i++)
	{
		if (_strcmp(aliases[i], "x") == 0)
		{
			aliases[i] = new;
			return (0);
		}
		index = 0;
		while (aliases[i][index] != '=')
			index++;
		if (_strncmp(argv[1], aliases[i], index) == 0 && len == index)
		{
			free(aliases[i]);
			aliases[i] = new;
			return (0);
		}
	}
	tmp = malloc(sizeof(char *) * (i + 2));
	if (!tmp)
	{
		free(new);
		return (-1);
	}

	for (i = 0; aliases[i]; i++)
		tmp[i] = aliases[i];

	free(aliases);
	aliases = tmp;
	aliases[i] = new;
	aliases[i + 1] = NULL;

	return (0);
}
