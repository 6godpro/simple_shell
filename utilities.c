#include "shell.h"


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *cpy1, *cpy2;
	int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	cpy1 = ptr;
	mem = malloc(sizeof(*cpy1) * new_size);
	if (mem == NULL)
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
