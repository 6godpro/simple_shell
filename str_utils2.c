#include "shell.h"

/**
 * _putchar - writes a character to STDOUT.
 * @c: Character to be displayed.
 * Return: returns 1.
 */
int _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);

	return (1);
}

/**
 * count_words - Counts the numbers of strings in
 *		 an array of string.
 * @str: The array of strings to be counted.
 * Return: The numbere of strings.
 */
int count_words(char **str)
{
	int i = 0, j, word = 0;

	while (str[i])
	{
		j = 0;
		while (1)
		{
			if (str[i][j] == '\0')
			{
				word++;
				break;
			}
			j++;
		}
		i++;
	}
	return (word);
}
