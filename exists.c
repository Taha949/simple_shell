#include "shell.h"

/**
 * _strncpy - entry point
 * @dest: Destination string to copy to
 * @src: Source string
 * @n: Number of characters to copy
 *
 * Return: The copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;

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
	return (result);
}

/**
 * _strncat - entry point
 * @dest: First string
 * @src: Second string
 * @n: Maximum number of bytes to use
 *
 * Return: The concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;

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
	return (result);
}

/**
 * _strchr - entry point
 * @s: String to be parsed
 * @c: Character to look for
 *
 * Return: A pointer to the memory area of s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

