/**
 * _strcmp - Compares two string
 *
 * @str_a: This is a pointer to the first null-terminated string to be compared.
 * @str_b: This is a pointer to the second null-terminated string to be compared.
 *
 * Return: 0 if both strings are equal
 	   -1 if @str_a < @str_b
	   1 if @str_a > @str_b
 */
int _strcmp(const char *str_a, const char *str_b)
{
	int diff = 0;

	while (*str_a == *str_b && *str_a != '\0')
	{
		str_a++;
		str_b++;
	}

	if (*str_a != *str_b)
		diff = *str_a - *str_b;

	return (diff);
}
