#include "shell.h"


dir_t *add_node_end(dir_t **head, char *dir)
{
	dir_t *new, *last;

	new = malloc(sizeof(dir_t));
	if (!new)
		return (NULL);

	new->dir = dir;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}

	return (new);
}

void free_list(dir_t *head)
{
	dir_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->dir);
		free(head);
		head = tmp;
	}
}


dir_t *get_path(char *path)
{
	int index;
	char **dirs;
	dir_t *head = NULL;
	char *copy;

	copy = malloc(strlen(path) + 1);

	if (!copy)
		return (NULL);

	strcpy(copy, path);
	dirs = tok_arr(copy, ":");

	if (!dirs)
	{
		free(copy);
		return (NULL);
	}
	for (index = 0; dirs[index]; index++)
	{
		if (add_node_end(&head, dirs[index]) == NULL)
		{
			free(copy);
			free(dirs);
			free_list(head);
			return (NULL);
		}
	}
	free(copy);
	free(dirs);
	return (head);
}
