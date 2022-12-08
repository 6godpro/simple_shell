#include "shell.h"


char *find(char *command)
{
	char **path, *tmp;
	dir_t *dir_path, *copy;
	struct stat sb;

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);

	dir_path = get_path(*path + 5);
	copy = dir_path;
	while (dir_path)
	{
		tmp = malloc(strlen(dir_path->dir) + strlen(command) + 2);
		if (!tmp)
			return (NULL);
		strcpy(tmp, dir_path->dir);
		strcat(tmp, "/");
		strcat(tmp, command);
		if (stat(tmp, &sb) == 0)
		{
			free_list(copy);
			return (tmp);
		}
		dir_path = dir_path->next;
		free(tmp);
	}
	if (stat(command, &sb) == 0)
		return (command);

	free_list(copy);
	return (NULL);
}
