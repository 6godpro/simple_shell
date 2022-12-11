#include "shell.h"

void sig_handler(int sig)
{
	char *prompt = "\n$ ";

	char *str = getenv("PWD");
	write(STDOUT_FILENO, "\n:", 2);
	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, "$ ", 2);
}
int main(int argc, char *argv[])
{
	int index, ret_val;
	char *line, *cmd, **builtincmd;


	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
	{
		while (1)
		{
			argv = _getline();
			if (!argv)
				return (-1);

			cmd = argv[0];
			if (cmd[0] != '\n' && strlen(cmd) != 0)
			{
				if (exec_builtin(argv) == -1)
				{
					if (execute_cmd(argv) == -1)
					{
						perror("./shell");
						ret_val = -1;
						break;
					}
				}
			}
			for (index = 1; argv[index]; index++)
				free(argv[index]);
			free(cmd);
			free(argv);
		}
		return (ret_val);
	}

	while (1)
	{
		char *str = getenv("PWD");
		write(STDOUT_FILENO, ":", 1);
		write(STDOUT_FILENO, str, _strlen(str));
		write(STDOUT_FILENO, "$ ", 2);

		argv = _getline();
		if (!argv || !(*argv))
			continue;

		cmd = argv[0];

		if (cmd[0] != '\n' && strlen(cmd) != 0)
		{
			if (exec_builtin(argv) == -1)
			{
				if (execute_cmd(argv) == -1)
				{
					perror("./shell");
					ret_val = -1;
					continue;
				}
			}
			else
				continue;
		}

		for (index = 1; argv[index]; index++)
			free(argv[index]);

		free(cmd);
		free(argv);
	}
	return (ret_val);
}
