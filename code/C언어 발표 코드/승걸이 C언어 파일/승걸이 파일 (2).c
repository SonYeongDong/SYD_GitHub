#include<stdio.h>

int main(void)
{
	int value[10],i,hol=0,jak=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",&value[i]);
		if(value[i]%2==1)
		{
			if(hol<value[i])
			hol=value[i];
		}
		if(value[i]%2==0)
		{
			if(jak<value[i])
			jak=value[i];
		}
	}
	printf("%d %d",hol,jak);
}
