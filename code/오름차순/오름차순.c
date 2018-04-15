#include <stdio.h>
main()
{
	int a[5]={4,8,2,7,6};
	int i, j, b, c; 
	for(i=0; i<6; i++)
	{
		if (a[i+1]<a[i])
		{
			b=a[i+1];
			a[i+1]=a[i];
			b=a[1];	
		}
	}
	for(i=0; i<5; i++)
	printf("%d", a[i]);
}
 
