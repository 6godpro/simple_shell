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


int _setenv(const char *name, const char *value)
{
	char *env_var, *new_value, **new_environ;
	int index, overwrite = 0;
	unsigned int len_name = _strlen(name);
	unsigned int len_value = _strlen(value);

	new_value = malloc(sizeof(char) * len_name + len_value + 2);
	if (!new_value)
		return (-1);

	strcpy(new_value, name);
	strcpy(new_value, "=");
	strcpy(new_value, value);

	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(name, environ[index], _strlen(name) == 0))
			env_var = environ[index];
		else
			continue;
	}

	printf("%s\n", env_var);
	if (env_var)
	{
		overwrite = 1;
		new_environ = malloc(sizeof(char *) * (index + 1));
	}
	else
		new_environ = malloc(sizeof(char *) * (index + 2));

	if (!new_environ)
	{
		free(new_value);
		printf("return from malloc new_env\n");
		return (-1);
	}

	//index = 0;
	/* do
	{
		new_environ[index] = malloc(strlen(environ[index] + 1));
		if (!new_environ[index])
		{
			for (index--; index >= 0; index--)
				free(new_environ[index]);
			free(new_environ);
			free(new_value);
			return (-1);
		}
		new_environ[index] = environ[index];
		index++;
	} while (environ[index]);*/

	for (index = 0; environ[index]; index++)
	{
		new_environ[index] = malloc(strlen(environ[index] + 1));
		if (!new_environ[index])
		{
			for(index--; index >= 0; index--)
				free(new_environ[index]);
 			free(new_environ);
			free(new_value);
			printf("return from free\n");
			return (-1);
		}
		strcpy(new_environ[index], environ[index]);
	}
	environ = new_environ;
	if (env_var && overwrite)
	{
		env_var = new_value;
		return (0);
	}
	environ[index] = new_value;
	environ[index + 1] = NULL;
	return (0);
}
