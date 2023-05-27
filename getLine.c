#include "shell.h"

/**
 * input_buf - met en mémoire tampon les commandes enchaînées
 * @info: structure des paramètres
 * @buf: adresse du tampon
 * @len: adresse de la variable len
 *
 * Return: octets lus
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* s'il ne reste rien dans le tampon, remplir */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* supprimer le saut de ligne final */
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) est-ce une chaîne de commandes ? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - obtient une ligne sans le saut de ligne
 * @info: structure des paramètres
 *
 * Return: octets lus
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* le tampon pour la chaîne de commandes ';' */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* il reste des commandes dans le tampon de la chaîne */
	{
		j = i; /* initialise un nouvel itérateur à la position actuelle du tampon */
		p = buf + i; /* obtient un pointeur pour le retour */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* itérer jusqu'au point-virgule ou à la fin */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* incrémente après le point-virgule annulé */
		if (i >= len) /* atteint la fin du tampon ? */
		{
			i = len = 0; /* réinitialise la position et la longueur */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* retourne un pointeur vers la position actuelle de la commande */
		return (_strlen(p)); /* retourne la longueur de la commande actuelle */
	}

	*buf_p = buf; /* sinon, ce n'est pas une chaîne, retourne le tampon de _getline() */
	return (r); /* retourne la longueur du tampon de _getline() */
}

/**
 * read_buf - lit un tampon
 * @info: structure des paramètres
 * @buf: tampon
 * @i: taille
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - obtient la ligne suivante de l'entrée standard
 * @info: structure des paramètres
 * @ptr: adresse du pointeur vers le tampon, pré-alloué ou NULL
 * @length: taille du tampon pré-alloué si non NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* ÉCHEC DE L'ALLOCATION DE MÉMOIRE ! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - bloque ctrl-C
 * @sig_num: le numéro de signal
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

