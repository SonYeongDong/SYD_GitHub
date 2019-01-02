#include <stdio.h>
main()
{
	int num, sum=0;
	scanf("%d", &num);
	while(num>0)
	{
		sum=sum+num;
		num--;
	}
	printf("%d", sum);
}
