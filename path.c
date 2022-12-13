#include "shell.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 * @head: pointer to pointer to list_t struct.
 * @dir: name of str member in the struct.
 * Return: Address to the new elelemt.
 *	   O/w, return NULL.
 */
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
			last = last->next;

		last->next = new;
	}
	return (new);
}

/**
 * free_list - frees a dir_t list.
 * @head: list to be freed.
 *
 * Return: void.
 */
void free_list(dir_t *head)
{
	dir_t *tmp;

	if (head == NULL)
		return;

	while (head)
	{
		tmp = head->next;
		free(head->dir);
		free(head);
		head = tmp;
	}
}

/**
 * get_path - creates a linked dir_t list.
 * @path: list of directories separated by
 *	  colon (:).
 * Return: Pointer to the head of the list
 *	   on success, NULL on error.
 */
dir_t *get_path(char *path)
{
	int index;
	char **dirs, *copy;
	dir_t *head = NULL;

	copy = malloc(_strlen(path) + 1);

	if (!copy)
		return (NULL);

	_strcpy(copy, path);
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
	free(dirs);
	free(copy);
	return (head);
}
