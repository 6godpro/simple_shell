#include "shell.h"


int _exits(const char *argv)
{
	int i, num = 0;

	if (argv)
	{
		for (i = 0; argv[i]; i++)
		{
			/* if (argv[i] == '-')
			{
				printf("./shell: Illegal Number: %s\n", argv);
				return (0);
			} */
			if (argv[i] >= '0' && argv[i] <= '9')
			{
				num = (num * 10) + (argv[i] - '0');
			}
			else
			{
				printf("./shell: Illegal Numbel: %s\n", argv);
				return (0);
			}
		}
		printf("Goodbye, see you soon!\n");
		exit (num);
	} 

	printf("Goodbye, see you soon!\n");
	exit(0);
}
