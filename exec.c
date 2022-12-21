#include "shell.h"

/**
 * execute_cmd - executes a command.
 * @argv: array of arguments and command
 *	 name.
 * Return: 0 on success, -1 on error.
 *
 */
int execute_cmd(char **argv)
{
	pid_t pid;
	int ret, status;

	if (!argv)
		return (-1);

	argv[0] = find(argv[0]);

	if (argv[0] && access(argv[0], X_OK) == 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				return (-1);
			}
		}
		else
		{
			wait(&status);
			ret = WEXITSTATUS(status);
		}

		return (ret);
	}
	return (-1);
}
