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
		printf("Malloc successful with size %ld\n", *n);
	}
	
	for (i = 0; (get_int = fgetc(stream)) != EOF; i++)
	{
		printf("Loop Started\n");
		if ((i == *n - 2) && (get_int != 10))
		{
			printf("Realloc entered\n");
			*n *= 2;
			buffer = realloc(*lineptr, sizeof(char) * *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
			printf("Realloc succeed\n");
		}
		if (get_int == 10)
		{
			printf("Assign newline condition entered\n");
			printf("Newline: %d\n", get_int);
			(*lineptr)[nread++] = '\n';
			break;
		}
		printf("Assign characters entered\n");
		(*lineptr)[nread++] = get_int;
		printf("get_int value: %d\n", get_int);
	}

	printf("Assign NULL byte entered\n");
	(*lineptr)[nread] = '\0';
	printf("Assign NULL byte entered\n");
	if (nread == 0)
		return (EOF);
	return (nread);
}
