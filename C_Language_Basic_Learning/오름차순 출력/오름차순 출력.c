#include <stdio.h>
main()
{
	int n[5]={4,8,2,7,6};
	int tmp, i, j;
	
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
			{
				if(n[i]>n[j])
				{
					tmp=n[i];
					n[i]=n[j];
					n[j]=tmp;
				}	
			}
	}
	for(i=0; i<5; i++)
	{
		printf("%d", n[i]);
	}
}
