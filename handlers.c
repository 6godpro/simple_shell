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
