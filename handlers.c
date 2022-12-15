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
 * setenv_handler - Handles the _setenv function in
 *		    in exec_builtin function.
 * @av: Array of character pointers to the arguments.
 *
 * Return: 0 on success, 1 on error.
 */
int setenv_handler(char **av)
{
	char *error_msg = "Usage: setenv variable value\n";
	int len = _strlen(error_msg);

	if (!av[1] || !av[2])
	{
		write(STDOUT_FILENO, error_msg,  len);
			return (0);
	}

	if (_setenv(av[1], av[2]) == 1)
	{
		write(STDERR_FILENO, "failed\n", 7);
			return (0);
	}
	return (1);
}
