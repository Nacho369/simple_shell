#include "main.h"

void _strncpy(char *dest, char *src, int ch_fr, int ch_to);

/**
 * _strtok - Tokenize string
 * @str: String to tokenize
 * @delim: Array of Delimeters to use
 *
 * Return: Array of split strings
 */
char **_strtok(char *str, const char *delim)
{
	char **str_arr;
	int indx, indx2, word_num = 1;

	if (str == NULL || delim == NULL)
		return (NULL);

	for (indx = 0; str[indx]; indx++)
	{
		for (indx2 = 0; delim[indx2] != '\0'; indx2++)
		{
			if (str[indx] == delim[indx2])
				word_num++
		}
	}

	str_arr = malloc(sizeof(char *) * word_num);
	if (str_arr == NULL)
		return (NULL);

	tok_count = 0;
	tok_start = 0;
	tok_len = 0;

	for (indx = 0; str[indx] '\0'; indx++)
	{
		for (indx2 = 0; delim[indx2] != '\0'; indx2++)
		{
			if (str[indx] == delim[indx2])
			{
				tok_len = indx - tok_start;
				str_arr[tok_count] = malloc(sizeof(char) * tok_len);
				if (str_arr[tok_count] == NULL)
				{
					for (rev = tok_count; rev != 0; rev--)
						free(str_arr[tok_count]);
					free(str_arr);
					return (-1);
				}
				_strncpy(str[tok_count], str, tok_start, indx);
				tok_count++;
				tok_start = indx + 1;
			}
		}
	}

	return (str_arr);
}


/**
 * _strncpy - Copies a string
 *
 * @dest: Buffer pointed to be copied into
 * @src: string to be copied from
 * @n: limit of string to copy from src
 *
 * Return: Pointer to the resulting string dest
 *
 */
void _strncpy(char *dest, char *src, int ch_fr, int ch_to)
{
	int indx, iter;

	for (indx = ch_fr, iter = 0; src[indx] != '\0'; indx++, iter++)
		dest[iter] = src[indx];

	dest[iter] = '\0';
}
