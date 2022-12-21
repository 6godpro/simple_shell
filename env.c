#include "shell.h"


/**
  * print_env - Prints the current environment.
  *
  * Return: void.
  */
void print_env(void)
{
	int index;

	if (!environ)
		return;

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);

	}
}

/**
 * _getenv - searches the environment variable
 *	     array for possible match of an
 *	     environment variable.
 * @var: Variable to be searched for.
 * Return: The address of the environment var-
 *	   iable if found.
 *	    O/w - NULL.
 */
char **_getenv(const char *var)
{
	int index, len;

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

/**
 * _setenv - Adds an environment variable to the PATH
 *	     or changes the value if the variable e-
 *	     xists.
 * @name: Name of the variable to be changed or added.
 * @value: Value of the variable.
 *
 * Return: 0 on success, 1 on error.
 */
int _setenv(char *name, char *value)
{
	char *new_value, **new_environ, **env_var;
	int index;
	int len_name = _strlen(name);
	int len_value = _strlen(value);

	new_value = malloc(len_name + len_value + 2);
	if (!new_value)
		return (1);

	_strcpy(new_value, name);
	_strcat(new_value, "=");
	_strcat(new_value, value);

	env_var = _getenv(name);
	if (env_var)
	{
		*env_var = new_value;
		return (0);
	}
	for (index = 0; environ[index]; index++)
		;
			
	new_environ = malloc(sizeof(char *) * (index + 2));
	if (!new_environ)
	{
		free(new_value);
		return (1);
	}

	for (index = 0; environ[index]; index++)
		new_environ[index] = environ[index];

	environ = new_environ;
	environ[index] = new_value;
	environ[index + 1] = NULL;
	return (0);
}


/**
 * _unsetenv - Deletes an environmental variable from the PATH.
 * @name: A pointer to the name of the variable.
 *
 * Return: If an error occurs - 1.
 *         Otherwise - 0.
 */
int _unsetenv(char *name)
{
	char **env_var, **copy;
	int index = 0, copy_index = 0;

	env_var = _getenv(name);
	if (!env_var)
		return (0);

	while (environ[index++])
		;

	copy = malloc(sizeof(char *) * index);
	if (!copy)
		return (1);

	index = 0;
	while (environ[index++])
	{
		if (*env_var == environ[index])
		{
			free(*env_var);
			continue;
		}
		copy[copy_index++] = environ[index];
	}
	free(environ);
	environ = copy;
	environ[index - 1] = NULL;

	return (0);
}
