#include <stdio.h>
main()
{
	int arr[5]={10, 20, 30, 40, 50};
	
	printf("%d %d %d\n", sizeof(arr), sizeof(arr[0]), sizeof(&arr[0]));
}
