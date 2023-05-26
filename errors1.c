#include "shell.h"

/**
 * _erratoi - entry point
 * @s: une chaine
 *
 * Return: 0 ou -1
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;
	int sign = 1;

	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}

	return (sign * result);
}

/**
 * print_error - entry point
 * @info: une structure
 * @estr: une chaîne
 *
 * Return: void
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - entry point
 * @input: an int
 * @fd: descripteur
 *
 * Return: number of chars
 */
int print_d(int input, int fd)
{
	int count = 0;
	int absolute = (input < 0) ? -input : input;

	if (input < 0)
		count += _putfd('-', fd);

	if (absolute >= 10)
		count += print_d(absolute / 10, fd);

	count += _putfd('0' + (absolute % 10), fd);

	return (count);
}

/**
 * convert_number - entry point
 * @num: nombre
 * @base: base
 * @flags: indicateurs d'argument
 *
 * Return: chaine
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char *ptr = &buffer[49];
	unsigned long n = num;
	char sign = 0;
	const char *array = (flags & CONVERT_LOWERCASE) ?
		"0123456789abcdef" : "0123456789ABCDEF";

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * remove_comments - entry point
 * @buf: l'adresse de la chaîne à modifier
 *
 * Return: void
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}

