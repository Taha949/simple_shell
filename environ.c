#include "shell.h"

/**
 * print_environment - entry point
 * @info: Structure
 * Return: 0
 */
int print_environment(info_t *info)
{
	list_t *node = info->env;

	while (node)
	{
		_puts(node->str);
		_putchar('\n');
		node = node->next;
	}

	return (0);
}

/**
 * get_environment_variable - entry point
 * @info: Structure
 * @name: environment variable name
 *
 * Return: the variable or null
 */
char *get_environment_variable(info_t *info, const char *name)
{
	list_t *node = info->env;

	while (node)
	{
		char *str = node->str;
		int i = 0;

		while (str[i] != '=')
		{
			if (str[i] == '\0')
				break;
			i++;
		}

		if (_strncmp(str, name, i) == 0 && name[i] == '=')
			return (str + i + 1);

		node = node->next;
	}

	return (NULL);
}

/**
 * set_environment_variable - entry point
 * @info: Structure
 * @name: environment variable name
 * @value: environment variable value
 *
 * Return: 0
 */
int set_environment_variable(info_t *info, const char *name, const char *value)
{
	char *env_var = _strcat3(name, "=", value);
	list_t *node = info->env;

	while (node)
	{
		char *str = node->str;
		int i = 0;

		while (str[i] != '=')
		{
			if (str[i] == '\0')
				break;
			i++;
		}

		if (_strncmp(str, name, i) == 0 && name[i] == '=')
		{
			free(node->str);
			node->str = env_var;
			return (0);
		}

		node = node->next;
	}

	add_node_end(&(info->env), env_var, 0);
	return (0);
}

/**
 * unset_environment_variable - entry point
 * @info: Structure
 * @name: environment variable name
 * Return: 0
 */
int unset_environment_variable(info_t *info, const char *name)
{
	list_t **head = &(info->env);
	list_t *prev = NULL;
	list_t *node = *head;

	while (node)
	{
		char *str = node->str;
		int i = 0;

		while (str[i] != '=')
		{
			if (str[i] == '\0')
				break;
			i++;
		}

		if (_strncmp(str, name, i) == 0 && name[i] == '=')
		{
			if (prev == NULL)
				*head = node->next;
			else
				prev->next = node->next;
			free(node->str);
			free(node);
			return (0);
		}

		prev = node;
		node = node->next;
	}

	return (0);
}

/**
 * populate_environment_list - entry point
 * @info: Structure
 *
 * Return: 0
 */
int populate_environment_list(info_t *info)
{
	extern char **environ;
	char **envp = environ;
	list_t **head = &(info->env);

	while (*envp)
	{
		add_node_end(head, _strdup(*envp), 0);
		envp++;
	}

	return (0);
}

