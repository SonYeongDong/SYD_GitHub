#include <stdio.h>
int main()
{
	int array[8]={5,9,10,3,7,2,12};
	int min;
	int i;
	min=0;
	for(i=1;i<7;i++)
		if(array[min]>array[i]) //i�� ��� n�̶� �� �� �־�!!  
		min=i;
	printf("�ּڰ��� %d �Դϴ�",array[min]);
}
