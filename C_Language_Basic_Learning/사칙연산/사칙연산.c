#include <stdio.h>
main()
{
int a, b, c;
	printf("ù��° ������ �Է��ϼ���");
	scanf("%d", &a);
	printf("+,-,*,/��ȣ�� �ϳ��� �Է��ϼ���");
	fflush(stdin);
	scanf("%c", &b);
	printf("�ι�° ������ �Է��ϼ���"); 
	scanf("%d", &c);
	switch(b)
	{
		case '+': printf("%d %c %d=%d", a, b, c, a+c);
		break; 
		case '-': printf("%d %c %d=%d", a, b, c, a-c);
		break; 	
		case '*': printf("%d %c %d=%d", a, b, c, a*c);
		break; 
		case '/': printf("%d %c %d=%d", a, b, c, a/c);
		break; 
	}
}
