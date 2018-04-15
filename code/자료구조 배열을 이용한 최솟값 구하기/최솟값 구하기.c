#include <stdio.h>
int main()
{
	int array[8]={5,9,10,3,7,2,12};
	int min;
	int i;
	min=0;
	for(i=1;i<7;i++)
		if(array[min]>array[i]) //i너 없어도 n이랑 살 수 있어!!  
		min=i;
	printf("최솟값은 %d 입니다",array[min]);
}
