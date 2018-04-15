#include <stdio.h>
int f(int n)
{
	if(n>0)
	{	
	f(n-1);
	printf("*");
	}
}
main()
{
	int n;
	scanf("%d",&n);
	f(n);
}
