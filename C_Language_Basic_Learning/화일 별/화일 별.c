#include <stdio.h>
main()
{
	int i=0, j=0;
	scanf("%d", &i);
	while(i>0)
	{
	i=j;
	while(j>0)
	{
	printf("*");
	j--;
	}
	i--;
	printf("\n");
	}
}
