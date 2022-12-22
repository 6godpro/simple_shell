#include "shell.h"


/**
 * sig_handler - Displays a new prompt if a signal
 *		 is encountered.
 * @sig: ...
 */
void sig_handler(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * setenv_handler - Handles the setenv command in
 *		    in exec_builtin function.
 * @av: Array of character pointers to the arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int setenv_handler(char **av)
{
	char *error_msg = "Usage: setenv variable value\n";
	int len = _strlen(error_msg), words;

	words = count_words(av);

	if (words != 3)
	{
		write(STDERR_FILENO, error_msg, len);
		return (1);
	}
	if (_setenv(av[1], av[2]) == 1)
	{
		write(STDERR_FILENO, "failed\n", 7);
		return (1);
	}
	return (0);
}


/**
 * unsetenv_handler - Handles the unsetenv command in
 *		      in exec_builtin function.
 * @av: Array of character pointers to the arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int unsetenv_handler(char **av)
{
	char *error_msg = "Usage: unsetenv variable\n";
	int len = _strlen(error_msg), words;

	words = count_words(av);

	if (words != 2)
	{
		write(STDOUT_FILENO, error_msg, len);
		return (1);
	}

	if (_unsetenv(av[1]) == 1)
	{
		write(STDERR_FILENO, "failed\n", 7);
		return (1);
	}
	return (0);
}

/**
 * alias_handler - handles the functionality of the builtin
 *		   alias command.
 * @argv:...
 * Return: 0 on success, -1 on error.
 */
/*int alias_handler(char **argv)
{
	int i = 0, words;
	char *name;
	extern char **tmp;

	tmp = NULL;

	words = count_words(argv);
	if (words == 0)
		return (1);

	if (words == 1 && tmp)
	{
		print_alias(tmp, NULL);
		return (0);
	}
	name = argv[1];
	if (name == NULL)
		return (1);
	if (!tmp)
	{
check_alias:
		while (name[i])
		{
			if (name[i] == '=')
			{
				if (i == 0 || name[i + 1] == '\0')
					return (1);
				if (set_alias(tmp, argv) == -1)
					return (1);
				return (0);
			}
			i++;
		}
		goto print_alias;
	}
	if (tmp)
	{
		goto check_alias;
print_alias:
		print_alias(tmp, name);
	}
	return (0);
}*/

/**
 * print_alias - prints alias at an index or the entire
 *		 list of aliases.
 * @alias: alias to be printed.
 * @list: ...
 * Return: void
 * Desc: if alias is NULL, it prints the list of
 *	 aliases, else it prints the specified alias.
 */
/*void print_alias(char **list, char *alias)
{
	int i, len;

	if (!list)
		return;
	for (i = 0; list[i]; i++)
	{
		if (alias == NULL)
		{
			write(STDOUT_FILENO, list[i], _strlen(list[i]));
			write(STDOUT_FILENO, "\n", 1);
			continue;
		}
		len = 0;
		while (list[i][len] != '=')
			len++;
		if (_strncmp(alias, list[i], len) == 0 && _strlen(alias) == len)
		{
			write(STDOUT_FILENO, list[i], _strlen(list[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}*/
