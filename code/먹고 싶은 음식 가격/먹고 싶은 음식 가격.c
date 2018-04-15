#include <stdio.h>

int main(void)
{
	int select;
	
	printf("가격을 알고 싶은 음식을 선택하십시오.\n");
	printf("1.팥빙수\n2.아이스크림\n3.샤베트\n");
	scanf("%d", &select);
	switch(select)
	{
	case 1 :
		printf("5000원입니다.\n");
		break; 
	case 2 :
		printf("3000원입니다.\n");
		break; 
	case 3 :
		printf("4000원입니다.\n");
		break; 
	default:
		printf("잘못된 입력입니다.\n");
		
	}
	return 0;	
}
