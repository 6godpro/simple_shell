#include "shell.h"

int execute_cmd(char **argv)
{
	pid_t pid;
	/* int flag; */

	if (argv[0][0] == '/')
	{
		/* flag = 1; */
		argv[0] = find(argv[0]);
	}
	/* if (argv[0] == NULL) */
		/* return (-1); */

	pid = fork();

	if (pid == -1)
	{
		/* if (flag) */
			/* free(argv[0]); */
		perror("fork failed");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("./shell");
	}
	else
		wait(NULL);

	/* if (flag) */
		/* free(argv[0]); */

	return (0);
}
