#include <stdio.h>
main()
{
	int a1, b1, a2, b2, a3, b3, c1, c2, c3;
	printf("첫번째 운동장의 가로와 세로 크기를 입력하세요.");
	scanf("%d %d", &a1, &b1);
	printf("두번째 운동장의 가로와 세로 크기를 입력하세요.");
	scanf("%d %d", &a2, &b2); 
	printf("세번째 운동장의 가로와 세로 크기를 입력하세요.");
	scanf("%d %d", &a3, &b3);
	c1=a1*b1;
	c2=a2*b2;
	c3=a3*b3; 
	if(c1>c2&&c1>c3)
	{
		printf("첫번째 운동장이 가장 넓습니다.\n첫번째 운동장의 크기:%dm", c1);
	 }
	 else if(c2>c1&&c2>c3)
	{
		printf("두번째 운동장이 가장 넓습니다.\n두번째 운동장의 크기:%dm", c2);
	 } 
	 else if(c3>c1&&c3>c2)
	{
		printf("세번째 운동장이 가장 넓습니다.\n세번째 운동장의 크기:%dm", c3);
	 }  
}
