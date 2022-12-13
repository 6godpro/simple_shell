#include "shell.h"

/**
 * main - entry point to a simple UNIX command interpreter.
 * @argc: ...
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int ret_val = 0;
	char *cmd;
	ssize_t len = 0;

	while (len >= 0)
	{
		signal(SIGINT, sig_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		argv = get_input(&len);
		if (!argv || !argv[0])
			continue;

		if (len == -1 && isatty(STDIN_FILENO))
			break;

		cmd = argv[0];
		if (cmd[0] != '\n' && _strlen(cmd) != 0)
		{
			if (exec_builtin(argv) == -1)
			{
				ret_val = execute_cmp(argv);
				if (ret_val == -1)
				{
					perror("./shell");
					ret_val = -1;
				}
			}
		}
		free_args(argv);

	}
	return (ret_val);
}
