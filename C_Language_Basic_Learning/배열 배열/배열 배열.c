#include <stdio.h>
main()
{
	int aList[3][4]={0};
	int i, j, a=-1;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			a=a+2;
			aList[i][j]=a;
			printf("%d\t", a);
		}
		printf("\n");
	}
}
