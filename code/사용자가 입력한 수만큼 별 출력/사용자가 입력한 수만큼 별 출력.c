#include <stdio.h>
main()
{
	int a, b=1;
INPUT:	
		printf("1~9까지의 값을 입력하세요.");
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
	 	printf("입력 값이 잘못되었습니다.\n다시 입력하세요.\n");
	 			goto INPUT;  
		}
		else if (a>=10)
		{
	 	printf("입력 값이 잘못되었습니다.\n다시 입력하세요.\n");
	 			goto INPUT;  
		}
		printf("\n");
}














