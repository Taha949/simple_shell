#include "shell.h"

/**
 * _strlen - renvoie la longueur d'une chaîne de caractères
 * @s: la chaîne de caractères dont on veut connaître la longueur
 *
 * Return: la longueur de la chaîne de caractères
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - effectue une comparaison lexicographique de deux chaînes de caractères.
 * @s1: la première chaîne de caractères
 * @s2: la deuxième chaîne de caractères
 *
 * Return: un nombre négatif si s1 < s2, un nombre positif si s1 > s2, zéro si s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - vérifie si needle commence par haystack
 * @haystack: la chaîne de caractères à rechercher
 * @needle: la sous-chaîne à trouver
 *
 * Return: l'adresse du caractère suivant de haystack ou NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatène deux chaînes de caractères
 * @dest: le tampon de destination
 * @src: le tampon source
 *
 * Return: un pointeur vers le tampon de destination
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

