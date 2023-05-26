#include <stdio.h>
#include <ctype.h>

/**
 * interactive - entry point
 * @info: adresse
 * Return: 1 or 0
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - entry point
 * @c: a char
 * @delim: a string
 * Return: 1 or 0
 */
int is_delim(char c, char *delim)
{
    while (*delim != '\0')
    {
        if (c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/**
 * is_alpha - entry point
 * @c: an int
 * Return: 1 or 0 
 */
int is_alpha(int c)
{
    return isalpha(c);
}

/**
 * atoi_custom - entry point
 * @s: a string
 * Return: 0 or other number (int)
 */
int atoi_custom(char *s)
{
    int i = 0;
    int sign = 1;
    int output = 0;

    if (s[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    while (s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            output = output * 10 + (s[i] - '0');
            i++;
        }
        else
        {
            break;
        }
    }

    return output * sign;
}

