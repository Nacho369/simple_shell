#include <stdio.h>
#include <stdlib.h>

/**
 * Function that prints each char of argv
 * 
 */
int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;

	while (*(av + i))
	{
		printf("%s\n", *(av + i));
		i++;
	}
	return (0);
}
