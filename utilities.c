#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the previously allocated memory.
 * @old_size: The size in bytes of ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: ptr - If new_size == old_size.
 *         NULL - If new_size == 0 and ptr is not NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *cpy1, *cpy2;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	cpy1 = ptr;
	mem = malloc(sizeof(*cpy1) * new_size);
	if (!mem)
	{
		free(ptr);
		return (NULL);
	}
	cpy2 = mem;
	for (i = 0; i < old_size && i < new_size; i++)
		cpy2[i] = *cpy1++;

	free(ptr);
	return (mem);
}
