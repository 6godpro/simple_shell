#include "shell.h"

/**
 * count_token - Counts the number of token on
 *		 the command line.
 * @str: String to be evaluated.
 * @delim:  The delimiter.
 * Return: The number of tokens.
 */
int count_token(char *str, const char *delim)
{
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
	return (words);
}

/**
 * letters_len - Counts the number of letters on the
 *	      the command line before the delimiter.
 * @str: String to be evaluated.
 * @delim:  The delimiter.
 * Return: The number of letters.
 */
int letters_len(char *str, const char *delim)
{
	int len = 0, index = 0;

	while (str[index] && str[index] != *delim)
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * _strtok - splits a string into series of tokens.
 * @str: String to be tokenized.
 * @delim: Specifies the delimiter.
 * Return: The tokenized string.
 *	   O/w - NULL.
 */
char **_strtok(char *str, const char *delim)
{
	char **arr;
	int tokens, letters, i, j, index = 0;

	tokens = count_token(str, delim);

	arr = malloc(sizeof(char *) * (tokens + 1));
	if (!arr)
		return (NULL);

	for (i = 0; i < tokens; i++)
	{
		while (str[index] == *delim)
			index++;
		letters = letters_len(str + index, delim);

		arr[i] = malloc(letters + 1);
		if (!arr[i])
		{
			for (i -= 1; i >= 0; i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		for (j = 0; j < letters; j++)
		{
			arr[i][j] = str[index];
			index++;
		}
		arr[i][j] = '\0';
	}
	arr[i] = NULL;

	return (arr);
}
