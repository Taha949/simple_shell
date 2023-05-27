#include "shell.h"

/**
 * _strcpy - copie une chaîne de caractères
 * @dest: la destination
 * @src: la source
 *
 * Return: un pointeur vers la destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplique une chaîne de caractères
 * @str: la chaîne de caractères à dupliquer
 *
 * Return: un pointeur vers la chaîne de caractères dupliquée
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - affiche une chaîne de caractères
 * @str: la chaîne de caractères à afficher
 *
 * Return: rien
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - écrit le caractère c sur stdout
 * @c: Le caractère à imprimer
 *
 * Return : En cas de réussite, 1.
 * En cas d'erreur, -1 est retourné et errno est configuré correctement.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

