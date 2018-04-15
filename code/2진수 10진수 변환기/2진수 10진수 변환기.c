#include <stdio.h>
main()
{
int ten, a=0,b,i;
int two[16]={0};
printf("2진수로 바꿀 10진수를 입력하세요:");
scnaf("%d", &ten);
b=ten%2;
printf("2)%d %d\n", ten,b);
printf("-----\n");
two[0]=b;
a++;
while(ten>=1)
{
	ten/=2;
	b=ten%2;
	two[a]=b;
	a++;
	if(ten==0)
	{
		printf("     0\n");
		break;
	}
	printf("2) %d %d\n",ten,b);
	printf("------\n");
}
for(i=16; i>=0; i--)
{
	printf("%d", two[i]);
}
}
