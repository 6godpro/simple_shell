#include "shell.h"


char *find(char *command)
{
	char **path, *tmp;
	dir_t *dir_path, *copy;
	struct stat sb;

	if (stat(command, &sb) == 0)
		return (command);

	path = _getenv("PATH");
	printf("%s\n", *path);

	if (!path)
		return (NULL);

	dir_path = get_path(*path + 5);
	copy = dir_path;
	while (dir_path)
	{
		tmp = malloc(strlen(copy->dir) + strlen(command) + 2);
		if (!tmp)
			return (NULL);
		strcpy(tmp, copy->dir);
		strcat(tmp, "/");
		strcat(tmp, command);
		if (stat(tmp, &sb) == 0)
		{
			free_list(dir_path);
			return (tmp);
		}
		copy = copy->next;
		free(tmp);
	}
	free_list(dir_path);

	return (NULL);
}
