#include <stdio.h>
main()
{
	int a, b=1;
INPUT:	
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
	 	printf("�Է� ���� �߸��Ǿ����ϴ�.\n�ٽ� �Է��ϼ���.\n");
	 			goto INPUT;  
		}
		else if (a>=10)
		{
	 	printf("�Է� ���� �߸��Ǿ����ϴ�.\n�ٽ� �Է��ϼ���.\n");
	 			goto INPUT;  
		}
		printf("\n");
}














