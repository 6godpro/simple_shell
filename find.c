#include "shell.h"

/**
 * @path: provides location of the directory.
 */
char *find(char *command)
{
	char **path, *tmp;
	dir_t *dir_path, *copy;
	struct stat sb;

	if (stat(command, &sb) == 0)
		return (command);

	path = _getenv("PATH");
	if (!path || !(*path))
		return (NULL);

	dir_path = get_path(*path);
	copy = dir_path;
	while (dir_path)
	{
		tmp = malloc(strlen(dir_path->dir) + strlen(command) + 2);
		if (!tmp)
			return (NULL);
		_strcpy(tmp, dir_path->dir);
		_strcat(tmp, "/");
		_strcat(tmp, command);
		if (stat(tmp, &sb) == 0)
		{
			free_list(copy);
			return (tmp);
		}
		dir_path = dir_path->next;
		free(tmp);
	}

	free_list(copy);
	free_list(dir_path);

	return (NULL);
}
