#include "shell.h"

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *alias)
{
	while (alias != NULL)
	{
		_puts(alias->str);
		_putchar('\n');
		alias = alias->next;
	}

	return (0);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	if (add_node_end(&(info->alias), str, 0) == NULL)
		return (1);

	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	int index = get_node_index(info->alias,
			node_starts_with(info->alias, str, -1));

	if (index == -1)
		return (1);

	delete_node_at_index(&(info->alias), index);
	return (0);
}

/**
 * _myalias - entry point
 * @info: Structure
 *  Return: Always 0
 */

int _myalias(info_t *info)
{
	if (info->argc == 1)
	{
		print_alias(info->alias);
	}
	else
	{
		for (int i = 1; info->argv[i]; i++)
		{
			char *p = _strchr(info->argv[i], '=');

			if (p)
			{
				*p = '\0';
				set_alias(info, info->argv[i]);
			}
			else
			{
				print_alias(node_starts_with(info->alias, info->argv[i], '='));
			}
		}
	}

	return (0);
}
/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

