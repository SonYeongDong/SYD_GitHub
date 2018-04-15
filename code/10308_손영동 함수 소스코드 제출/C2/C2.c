#include <stdio.h>
int f(int a, int b)
{
	if(a>b)return a;
	else return b;
}
main()
{
	int a, b, c;
	scanf("%d %d %d",&a, &b, &c);
	printf("%d\n",f(a,f(b,c)));	
}
