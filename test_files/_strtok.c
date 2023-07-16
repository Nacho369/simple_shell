#include "main.h"

void _strncpy(char *dest, char *src, int ch_fr, int ch_to);

/**
 * _strtok - Tokenize string
 * @str: String to tokenize
 * @delim: Array of Delimeters to use
 *
 * Return: Array of split strings
 */
char **_strtok(char *str, const char *delim, int *num_tokens)
{
	char **str_arr;
	int indx, indx2, rev, word_num_est = 1;
	int tok_count, tok_start, tok_len;

	if (str == NULL || delim == NULL)
		return (NULL);

	for (indx = 0; str[indx]; indx++)
	{
		for (indx2 = 0; delim[indx2] != '\0'; indx2++)
		{
			if (str[indx] == delim[indx2])
			{
				word_num_est++;
				break;
			}
		}
	}

	str_arr = malloc(sizeof(char *) * word_num_est);
	if (str_arr == NULL)
		return (NULL);

	tok_count = 0; /* Each iteration of the array */
	tok_start = 0; /* Start of the tokenized string */
	tok_len = 0; /* Length of tokenized string */

	for (indx = 0; str[indx] != '\0'; indx++)
	{
		for (indx2 = 0; delim[indx2] != '\0'; indx2++)
		{
			if (str[indx] == delim[indx2])
			{
				tok_len = (indx + 1) - tok_start;
				str_arr[tok_count] = malloc(sizeof(char) * tok_len);
				if (str_arr[tok_count] == NULL)
				{
					for (rev = tok_count; rev != 0; rev--)
						free(str_arr[tok_count]);
					free(str_arr);
					return (NULL);
				}
				_strncpy(str_arr[tok_count], str, tok_start, indx);
				tok_count++;
				tok_start = indx + 1;
				break;
			}
		}
	}

	tok_len = (indx + 1) - tok_start;
	str_arr[tok_count] = malloc(sizeof(char) * tok_len);
	if (str_arr[tok_count] == NULL)
	{
		for (rev = tok_count; rev != 0; rev--)
			free(str_arr[tok_count]);
		free(str_arr);
		return (NULL);
	}
	_strncpy(str_arr[tok_count], str, tok_start, indx);
	tok_count++;
	*num_tokens = tok_count;

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
void _strncpy(char *dest, char *src, int start, int end)
{
	int indx, indx2;

	for (indx = start, indx2 = 0; indx < end; indx++, indx2++)
		dest[indx2] = src[indx];

	dest[indx2] = '\0';
}
