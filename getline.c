#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buff;
	ssize_t bytes_rd = 0;
	size_t size = *n;
	int ch;

	if (*lineptr == NULL)
	{
		size = 128;
		*lineptr = malloc(sizeof(char) * size);
		if (*lineptr == NULL)
			return (-1);
	}

	ch = fgetc(stream);

	while (ch != EOF && ch != '\n')
	{
		(*lineptr)[bytes_rd++] = ch;
		if (bytes_rd >= (size - 1))
		{
			size *= 2;
			buff = realloc(*lineptr, sizeof(char) * size);
			if (buff == NULL)
				return (-1);
			*lineptr = buff;
		}

		ch = fgetc(stream);
	}

	(*lineptr)[bytes_rd] = '\0';

	if (n == NULL)
		*n = size;

	return (bytes_rd);
}
