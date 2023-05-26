#include "shell.h"

/**
 * eputs - entry point
 * @str: the string
 *
 * Return: void
 */
void eputs(const char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			_eputchar(*str);
			str++;
		}
	}
}

/**
 * eputchar - entry point
 * @c: a char
 *
 * Return: 1 or -1
 */
int eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	i = 0;
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
 * put_to_fd - writes the character c to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_to_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	i = 0;
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
 * puts_to_fd - prints an input string to the given file descriptor
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters written
 */
int puts_to_fd(const char *str, int fd)
{
	int count = 0;

	if (str != NULL)
	{
		while (*str != '\0')
		{
			count += put_to_fd(*str, fd);
			str++;
		}
	}

	return (count);
}

