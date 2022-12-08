#include "shell.h"


int main(int argc, char *argv[])
{
	size_t n, index;
	char *line = NULL, *cmd;
	int ret_val;
	pid_t pid;

	/* if (argc != 1)
		return (execute_cmd(argv + 1)); */

	if (!isatty(STDIN_FILENO))
	{
		if (getline(&line, &n, stdin) == -1)
		{
			perror("read failed");
			free(line);
			return (-1);
		}
		argv = tok_arr(line, ":");

		while (argv)
		{
			cmd = argv[0];
			pid = fork();
			if (pid == -1)
				return (-1);
			if (pid == 0)
			{
				if (argv[0][0] == '/')
					argv[0] = find(argv[0]);
				if (execve(argv[0], argv, environ) == -1)
				{
					perror("./shell");
					return (-2);
				}
			}
			else
				wait(NULL);

			/* ret_val = execute_cmd(argv); */
			for (index = 1; argv[index]; index++)
				free(argv[index]);
			free(argv);
			free(cmd);
			argv = NULL;
			if (getline(&line, &n, stdin) == -1)
			{
				perror("read failed");
				free(line);
				return (-1);
			}
			argv = tok_arr(line, ":");	
		}
		free(argv);
	}
	while (1)
	{
		printf(":) ");
		n = 0;
		if (getline(&line, &n, stdin) == -1)
		{
			perror("read line failed\n");
			return (1);
		}
		argv = tok_arr(line, " ");
		if (!argv)
		{
			perror("tokenization error");
			continue;
		}
		cmd = argv[0];
		/* ret_val = execute_cmd(argv); */
		
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			if (argv[0][0] == '/')
				argv[0] = find(argv[0]);
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				return (-2);
			}
		}
		else
			wait(NULL);

		for (index = 1; argv[index]; index++)
			free(argv[index]);

		free(argv);
		free(cmd);
		free(line);
	}
	return (ret_val);
}
