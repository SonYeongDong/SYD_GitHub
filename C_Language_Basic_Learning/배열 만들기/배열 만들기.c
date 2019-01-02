#include <stdio.h>
main()
{
	int aList[5]={0};
	int i=0;
	
	for(i=0;i<5;i++)
		scanf("%d", &aList[i]);
	for(i=0;i<5;i++)
		printf("%d\n", aList[i]);
}
