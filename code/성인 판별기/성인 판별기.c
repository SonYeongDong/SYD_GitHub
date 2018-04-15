#include <stdio.h>

int main(void)
{
	int age; 
	scanf("%d", &age);
	if(age >= 18)
	{
		printf(" 성인입니다.\n");
	}
	else if(age >=13)
	{
		printf(" 청소년입니다.\n");
	}
	else
	{
		printf("어린이입니다.\n");
	}
	return 0;	
}
