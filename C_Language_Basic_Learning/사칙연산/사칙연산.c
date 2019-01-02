#include <stdio.h>
main()
{
int a, b, c;
	printf("첫번째 정수를 입력하세요");
	scanf("%d", &a);
	printf("+,-,*,/기호중 하나를 입력하세요");
	fflush(stdin);
	scanf("%c", &b);
	printf("두번째 정수를 입력하세요"); 
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
