#include <stdio.h>
main()
{
	int i=1, j=1;
	
	while(j<=5)
	{
		i=1;
		while(i<=j)
		{
			printf("*");
			i++;
		}
		printf("\n");
		j++;
	}

} 
