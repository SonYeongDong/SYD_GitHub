#include <stdio.h>
main()
{
	int i=6, j=6, a;
	while (i>0)
	{
		a=6-i;
		while (a>0)
		{
			printf(" ");
			a--;
		}
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
