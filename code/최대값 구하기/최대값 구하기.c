#include <stdio.h>
int main()
{
	int aList[5]={40, 30, 50, 20, 10};
	int tmp, max, i, j;
	
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
			{
				if(aList[i]>aList[j])
				{
					tmp=aList[i];
					aList[i]=aList[j];
					aList[j]=tmp;
				}	
			}
	}
	max=aList[4];
	printf("MAX: %d\n", max);
}
