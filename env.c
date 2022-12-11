#include "shell.h"

char **_getenv(const char *var)
{
	size_t index, len;

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
		{
			return (&environ[index]);
		}
	}

	return (NULL);
}
