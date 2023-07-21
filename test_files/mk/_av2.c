#include <stdio.h>
#include <stdlib.h>

/**
 * Function that prints each char of argv
 * 
 */
int main(int ac __attribute__((unused)), char **av)
{
	int j = 0;
	
	if (ac < 2)
	{
		printf("Supply 2 arguments\n");
		return (0);
	}
	while (av[1][j])
	{
		printf("%c\n", av[1][j]);
		j++;
	}
	return (0);
}
