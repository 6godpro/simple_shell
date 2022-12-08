#include "shell.h"


char **tok_arr(char *str, const char *delim)
{
	char *token;
	char **arr;
	int index;
	size_t words = 0;

	for (index = 0; str[index]; index++)
	{
		if (str[index] != *delim)
		{
			if (str[index + 1] == *delim ||
			    str[index + 1] == '\0')
				words++;
		}
	}
	str[index - 1] = '\0';
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
	return (NULL);

	token = strtok(str, delim);
	for (index = 0; token != NULL; index++)
	{
		arr[index] = malloc(strlen(token) + 1);
		if (!arr[index])
		{
			for (index -= 1; index >= 0; index--)
				free(arr[index]);
			free(arr);
			return (NULL);
		}
		strcpy(arr[index], token);
		token = strtok(NULL, delim);
	}
	arr[index] = NULL;
	return (arr);
}
