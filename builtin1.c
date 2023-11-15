#include "shell.h"

/**
 * _myhistory - shows the history oting at 0.
 * @info: Structurs contai ning potentials argume. Used to tain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - seting aliases to strings
 * @info: params structure
 * @str: the strings of alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *k, m;
	int ret;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	m = *k;
	*k = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*k = m;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: params structure
 * @str: the strings of  alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *j;

	j = _strchr(str, '=');
	if (!j)
		return (1);
	if (!*++j)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - printing an alis stringing
 * @node: the alias noding
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (a = node->str; a <= ptr; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copies aliasing builtin (woman alias)
 * @info: Struct having potential params. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		ptr = _strchr(info->argv[j], '=');
		if (ptr)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
