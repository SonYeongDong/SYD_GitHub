#include <stdio.h>

int main(void)
{
	int age; 
	scanf("%d", &age);
	if(age >= 18)
	{
		printf(" �����Դϴ�.\n");
	}
	else if(age >=13)
	{
		printf(" û�ҳ��Դϴ�.\n");
	}
	else
	{
		printf("����Դϴ�.\n");
	}
	return 0;	
}
