#include <stdio.h>
main()
{
	int a, b, c=0;
	printf("민서 동생과 민서의 나이를 입력하시오");
	scanf("%d %d", &a, &b);
	if(a>b)
	{
		c=a;
		a=b;
		b=c;
	}
	for(a; a<=b; a++)
	{
		printf("%d", a);
	}	
}
