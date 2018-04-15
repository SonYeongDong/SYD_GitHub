#include<stdio.h>
int main(void)
{
	int nAge;
	char name[5];
	printf("나이를 입력하세요: ");
	scanf("%d", &nAge);
	printf("이름을 입력하세요: ");
	scanf("%s", name);
	printf("당신의 나이는 %d이고 이름은 %s입니다.\n",nAge,name);
	return 0;
}
