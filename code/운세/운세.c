#include <stdio.h>
main()
{
	int a, b, c, d;
	printf("당신의 사주를 봐드립니다\n 연도, 월, 일을 차례대로 입력하세요");
	scanf("%d %d %d", &a, &b, &c);
	d=a+b+c;
	if (d%10==0)
	printf("대박");
	else 
	printf("그럭저럭"); 
 } 

