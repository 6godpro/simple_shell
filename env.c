#include "shell.h"

char **_getenv(const char *var)
{
	int index, len;

	len = strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (strncmp(var, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
