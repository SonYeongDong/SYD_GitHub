#include<stdio.h>
int main(void)
{
	int length=0, a=0, i=1,j=0;
	scanf("%d",&length);
	a=length/2;
	while(i<=a)
	{
		if(length%i==0){
		j++;
		}
		i++;
	}
	printf("%d",j);
	return 0;
}
