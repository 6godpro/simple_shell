#include "shell.h"

/* executes a command */
int execute_cmd(char **argv)
{
	pid_t pid;

	if (!argv)
		return (-1);

	argv[0] = find(argv[0]);

	if (!argv[0])
		return (-1);

	if (argv[0])
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
			wait(NULL);

		return (0);
	}
	return (-1);
}
