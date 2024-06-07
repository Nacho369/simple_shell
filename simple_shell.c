#include "main.h"


/**
 * main - Super simple shell
 *
 * @argc: Argument Count
 * @argv: Argument vector
 *
 * Return: 0 (Success)
 */
int main(void)
{
	ssize_t bytes;
	size_t size_n = 0;
	char *buffer = NULL;
	char *args[] = {};
	char *envp[] = {NULL};
	const char *delim = " ";
	char **buff_tok = NULL;
	int num;

	printf("nacho €=>> ");
	bytes = _getline(&buffer, &size_n, stdin);

	while (bytes != -1)
	{
		buff_tok = _strtok(buffer, delim, &num);

		if (_strcmp(buff_tok[0], "exit"))
			exit();

		cust_fork(buff_tok[0], buff_tok, envp);
		printf("nacho €=>> ");
		bytes = _getline(&buffer, &size_n, stdin);
	}

	free(buffer);
	return (0);
}
