#include <stdio.h>
main()
{
	int i=6, j=6;
	while (i>0)
	{
		j=i;
		while (j>0)
		{
			printf("*");
			j--;
		}
		i--;
		printf("\n");
	}
}
