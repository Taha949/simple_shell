#include "shell.h"

/**
 * _eputs - affiche une chaîne de caractères
 * @str: la chaîne de caractères à afficher
 *
 * Return: Rien
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - écrit le caractère c sur stderr
 * @c: Le caractère à imprimer
 *
 * Return: En cas de succès, renvoie 1.
 * En cas d'erreur, -1 est renvoyé et errno est défini correctement.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - écrit le caractère c sur le descripteur de fichier donné
 * @c: Le caractère à imprimer
 * @fd: Le descripteur de fichier où écrire
 *
 * Return: En cas de succès, renvoie 1.
 * En cas d'erreur, -1 est renvoyé et errno est défini correctement.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - affiche une chaîne de caractères
 * @str: la chaîne de caractères à afficher
 * @fd: Le descripteur de fichier où écrire
 *
 * Return: le nombre de caractères écrits
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

