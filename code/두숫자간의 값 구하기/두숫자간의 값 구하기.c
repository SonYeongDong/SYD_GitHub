#include <stdio.h>
main()
{
	int a, b, c=0;
	printf("�μ� ������ �μ��� ���̸� �Է��Ͻÿ�");
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
