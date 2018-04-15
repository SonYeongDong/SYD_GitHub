#include <stdio.h>
main()
{
	int arr1[8]={2,3,4,5,6,7,8,9};
	int arr2[9]={1,2,3,4,5,6,7,8,9};
	int i, j;
	for(i=0; i<9; i++)
	{
	 for(j=0; j<9; j++)
	 {
		printf("%d * %d = %d\n", arr1[i], arr2[j], arr1[i]*arr2[j]);
	 }
	}
}
