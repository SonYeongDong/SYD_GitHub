#include <stdio.h>
main()
{
	int a;
	printf("������ �Է��ϼ���");
	scanf("%d", &a);
	a=a/10;	
	switch(a)
	{
		case 9: printf("A"); break;
		case 8: printf("B"); break;
		case 7: printf("C"); break;
		case 6: printf("D"); break;
		default: printf("E");
	}
}
