#include "shell.h"

/**
 * interactive - renvoie true si le shell est en mode interactif
 * @info: adresse de la structure
 *
 * Return: 1 si en mode interactif, 0 sinon
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - vérifie si le caractère est un délimiteur
 * @c: le caractère à vérifier
 * @delim: la chaîne de délimiteurs
 *
 * Return: 1 si vrai, 0 si faux
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - vérifie si un caractère est alphabétique
 * @c: Le caractère à vérifier
 *
 * Return: 1 si c est alphabétique, 0 sinon
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convertit une chaîne de caractères en entier
 * @s: la chaîne de caractères à convertir
 *
 * Return: 0 s'il n'y a pas de
 * chiffres dans la chaîne, le nombre converti sinon
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

