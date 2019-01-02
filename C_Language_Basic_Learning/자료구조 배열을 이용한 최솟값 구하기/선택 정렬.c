#include <stdio.h>
#define swap(temp,a, b) ((temp)=(a), (a)=(b), (b)=(temp))
#include <limits.h>
void SelectionSort(int array[], int n);	
int main()
{
	int array[10000];
	int input, i=0;
	while(1)
	{
		scanf("%d", &input);
		if(input==9999)
		{
			SelectionSort(array,i);
			return 0;
		}
		array[i++]=input;	
	}
}

void SelectionSort(int arr[], int n)	
{
	int min;
	int i, j, temp;
	printf("\n ������ �迭 : ");
	for(j=1; j<n-1; j++)	//pass�� �����ϴ� ��Ȱ
	{
		min=j-1;
	
		for(i=1;i<n;i++)	//���ϴ� ���� 
			if(arr[min]>arr[i])   
				min=i;
	
		printf("�ּڰ��� %d �Դϴ�\n",arr[min]);
	
		swap(temp,arr[min],arr[j-1]);	//��ȯ�ϴ� ���� 
	
		printf("%dPASS : ",j);
		for(i=0;i<n;i++)
			printf("%d",arr[i]); 
		printf("\n\n");
	}
}   
