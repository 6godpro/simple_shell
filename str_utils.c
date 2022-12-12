#include "shell.h"

/**
 * _strlen: calculates the length of a string.
 * @str: ...
 * Return: The number of bytes in the string
 *	   pointed to by str.
 */
int _strlen(const char *str)
{
	int count;

	if (!str)
		return (-1);

	for (count = 0; str[count]; count++) 
		;

	return (count);
}

/**
 * _strncmp - function compares the first n bytes
 *	      two strings s1 and s2.
 * @s1: ...
 * @s2: ...
 * @n: number of characters to compare.
 * Return: 0 - if the strings are equal.
 *	   >0 - if s1 is greater than s2.
 *	   <0 - if s1 is lesser than s2:
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 1;

	if (!s1 || !s2)
		return (-33);

	while (i <= n)
	{
		if (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;

			if (i == n)
				return (0);
		}
		else
			break;
		i++;
	}

	return (*s1 - *s2);
}

/* read man page */
int _strcmp(const char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/* read man page */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/* read man page */
char *_strcat(char *s1, char *s2)
{
	int len1, i;

	len1 = _strlen(s1);

	for (i = 0; s2[i]; i++)
		s1[len1++] = s2[i];

	s1[len1] = '\0';

	return (s1);
}
