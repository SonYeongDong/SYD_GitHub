#include <stdio.h>
int f(int a, int b)
{
	if(a>b)return a;
	else return b; 
 } 
 
 
 main()
 {
 	int a, b;
 	scanf("%d %d",&a,&b);
 	printf("%d\n",f(a,b));
 }

