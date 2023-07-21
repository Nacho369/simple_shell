#include <stdio.h>
#include <stdlib.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - Entry point to print prompt and commands
 *
 * Return: 0 (Always Success)
 */
int main(void)
{
	char prmt[] = "\"$ \"";
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("%s", prmt);
	nread = _getline(&line, &len, stdin);
	if (nread < 1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	printf("%s", line);
	free(line);
	exit(EXIT_SUCCESS);
}
