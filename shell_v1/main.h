#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

char **_strtok(char *str, const char *delim, int *num_tokens);

void _strncpy(char *dest, char *src, int ch_fr, int ch_to);

int cust_fork(char *path, char *args[], char *envp[]);

int _strcmp(const char *str_a, const char *str_b);

#endif /* MAIN_H */
