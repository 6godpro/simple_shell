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
	char *cmd;

	if (!argv)
		return (-1);

	cmd = find(argv[0]);

	if (cmd && access(cmd, X_OK) == 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork failed");
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(cmd, argv, environ) == -1)
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
		free(cmd);
		return (ret);
	}
	return (-1);
}
