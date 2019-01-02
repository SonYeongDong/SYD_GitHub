#include <stdio.h>
int main(void)
{
	int i, j=0;
	char buf[10]={'0'};
	for(i=65; i<= 75; i++)
	{
		if(i%2==0) continue;
		else buf[j]=i;
		j++;
	}
	for(i=0; i<10; i++)
	{
		printf("%c", buf[i]);	
	}
}
