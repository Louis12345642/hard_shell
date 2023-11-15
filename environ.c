#include "shell.h"

/**
 * _myenv - prints the currenting environmests
 * @info: Structure containing potentialing arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gs the vale of an environs variables
 * @info: Structing containing potentialing arguments. Used to maintain
 * @name: env variable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *nds = info->env;
	char *ptr;

	while (nds)
	{
		ptr = starts_with(nds->str, name);
		if (ptr && *ptr)
			return (ptr);
		nds = nds->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initiassslsize as nesws environments varidf able.
 * @info: Structures contasinings potentials arguments. Using maintian
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - use for removing environ variables
 * @info: Structre containing potentialiai arging. Used to maintain
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - fills env linked list
 * @info: Structre contning potendfftial arts. Used to maintain
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *nd = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&nd, environ[i], 0);
	info->env = nd;
	return (0);
}
