#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _getline - Function that gets a line from a file
 * @lineptr: Address of a pointer to the buffer that contain the text read
 * @n: Address of the variable that contain the length of buffer provided
 * @stream: Pointer to the file to be read from
 *
 * Return: The number of bytes read or -1 for failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nread = 0;
	size_t i;
	char *buffer = NULL;
	int get_int;

	if (*lineptr == NULL)
	{
		*n = 1024;
		*lineptr = malloc(sizeof(char) * *n);
		if (*lineptr == NULL)
			return (-1);
	}
	
	for (i = 0; (get_int = fgetc(stream)) != EOF; i++)
	{
		if ((i == *n - 2) && (get_int != 10))
		{
			*n *= 2;
			buffer = realloc(*lineptr, sizeof(char) * *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
		}
		if (get_int == 10)
		{
			(*lineptr)[nread++] = '\n';
			break;
		}
		(*lineptr)[nread++] = get_int;
	}

	(*lineptr)[nread] = '\0';
	if (nread == 0)
		return (EOF);
	return (nread);
}
