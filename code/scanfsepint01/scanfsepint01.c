#include<stdio.h>
int main(void)
{
	int x, y;
	
	printf("두 정수를 입력하세요 : ");
	
	scanf("%d %d", &x, &y);
	printf(" 두 수의 합은 %d입니다.\n", x+y);
	
	return 0;
}
