#include <stdio.h>
int main()
{
	int array[]={5,9,10,3,7,2,12};
	int min;
	int n=sizeof(array)/4;
	min=0;
	for(;n>0;n--)
		if(array[min]>array[n-1])
		min=n-1;
	printf("�ּڰ��� %d �Դϴ�",array[min]);
} 
