#include<stdio.h>
main()
{
	int a, b;
	printf("두 수를 입력하세요:");
	scanf("%d %d", &a, &b);
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b); 
	printf("%d*%d=%d\n",a,b,a*b); 
	printf("%d/%d=%d\n",a,b,a/b);
	printf("%d%%%d=%d\n",a,b,a%b);			 
}
