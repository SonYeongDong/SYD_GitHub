#include <stdio.h>
main()
{
	int a, b=1;
		printf("1~9������ ���� �Է��ϼ���.");
		scanf("%d", &a);
		if (a>0 && a<10)
		{
			for(a; b<=a; b++)
			{
			printf("*");
			}
		}
		else if (a<1)
		{
	 	printf("*");  
		}
		else if (a>10)
		{
	 	printf("*********");  
		}
		printf("\n");
}
