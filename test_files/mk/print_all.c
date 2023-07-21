#include <stdio.h>
#include <stdlib.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (argc != 2) 
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) 
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = _getline(&line, &len, stream)) != EOF)
	{
		printf("Retrieved line of length %lu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
