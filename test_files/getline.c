#include "main.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	nread = getline(&line, &len, stream);
	while (nread != -1)
	{
		printf("Retrieved line of length %zu:\n", nread);
		printf("%s\n", line);
		nread = getline(&line, &len, stream);
	}

	/*
	while ((nread = _getline(&line, &len, stream)) != -1) {
		printf("Retrieved line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	*/

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}



/*
int main() {
    char *line = NULL;
    size_t size = 0;
    ssize_t characters_read;

    printf("Enter a line of text: ");
    characters_read = getline(&line, &size, stdin);

    if (characters_read != -1) {
        printf("You entered: %s\n", line);
    } else {
        printf("Failed to read input.\n");
    }

    free(line);
    return 0;
}
*/


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
