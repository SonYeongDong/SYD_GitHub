#include <stdio.h>
main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if(a+b>=100) printf("합격");
	else if(a+b<0) printf("그런 평균점수는 나올 수 없습니다");
	else printf("불합격"); 
}
