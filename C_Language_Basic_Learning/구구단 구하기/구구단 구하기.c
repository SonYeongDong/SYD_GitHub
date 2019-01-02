#include <stdio.h>
main()
{
	int a, b=1;
	scanf("%d",&a);
	if (a>=2 && a<10)
	{
		for(b; b<=9; b++)
		{
		printf("%d*%d=%d\n", a, b, a*b);
		}
	}
	else 
	{
		printf("ERROR");
	}
}
