#include "shell.h"

/**
 * _strncpy - copie une chaîne de caractères
 * @dest: la chaîne de destination où copier
 * @src: la chaîne source
 * @n: le nombre de caractères à copier
 * Return: la chaîne de destination copiée
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - concatène deux chaînes de caractères
 * @dest: la première chaîne
 * @src: la deuxième chaîne
 * @n: le nombre maximal d'octets à utiliser
 * Return: la chaîne concaténée
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - recherche un caractère dans une chaîne de caractères
 * @s: la chaîne à analyser
 * @c: le caractère à rechercher
 * Return: (s) un pointeur vers la zone mémoire s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

