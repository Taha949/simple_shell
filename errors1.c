#include "shell.h"

/**
 * _erratoi - convertit une chaîne de caractères en un entier
 * @s: la chaîne de caractères à convertir
 * Return: 0 s'il n'y a pas de nombres dans la chaîne, le nombre converti sinon
 *       -1 en cas d'erreur
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - affiche un message d'erreur
 * @info: la structure d'informations sur les paramètres et les retours
 * @estr: chaîne contenant le type d'erreur spécifié
 * Return: 0 si aucune valeur dans la chaîne, le nombre converti sinon
 *        -1 en cas d'erreur
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
 * print_d - fonction qui affiche un nombre décimal (entier) (base 10)
 * @input: l'entrée
 * @fd: le descripteur de fichier où écrire
 *
 * Return: le nombre de caractères affichés
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - fonction de conversion, un clone de itoa
 * @num: nombre
 * @base: base
 * @flags: indicateurs d'argument
 *
 * Return: une chaîne de caractères
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - remplace la première occurrence de '#' par '\0'
 * @buf: adresse de la chaîne de caractères à modifier
 *
 * Return: Toujours 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

