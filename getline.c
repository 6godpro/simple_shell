#include "shell.h"

/**
 * cpy_lineptr - Reassigns the lineptr variable for _getline.
 * @lineptr: A buffer to store an input string.
 * @n: The size of lineptr.
 * @buff: The string to assign to lineptr.
 * @byte: The size of buffer.
 */
void cpy_lineptr(char **lineptr, size_t *n, char *buff, size_t byte)
{
	if (*lineptr == NULL)
	{
		if (byte > 100)
			*n = byte;
		else
			*n = 100;
		*lineptr = buff;
	}
	else if (*n < byte)
	{
		if (byte > 100)
			*n = byte;
		else
			*n = 100;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytes;
	char c = 'c', *buff;
	int byte;
	static ssize_t count;

	if (count == 0)
		fflush(stream);
	else
		return (-1);
	count = 0;

	buff = malloc(100);
	if (!buff)
		return (-1);

	while (c != '\n')
	{
		byte = read(STDIN_FILENO, &c, 1);
		if (byte == -1 || (byte == 0 && count == 0))
		{
			free(buff);
			return (-1);
		}
		if (byte == 0 && count != 0)
		{
			count++;
			break;
		}
		if (count >= 100)
			buff = _realloc(buff, count, count + 1);

		buff[count] = c;
		count++;
	}
	buff[count] = '\0';
	cpy_lineptr(lineptr, n, buff, count);
	bytes = count;
	if (byte != 0)
		count = 0;
	return (bytes);
}
