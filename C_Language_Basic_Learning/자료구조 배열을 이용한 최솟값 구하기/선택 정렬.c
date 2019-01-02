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
	printf("\n 정렬한 배열 : ");
	for(j=1; j<n-1; j++)	//pass를 구분하는 역활
	{
		min=j-1;
	
		for(i=1;i<n;i++)	//비교하는 라인 
			if(arr[min]>arr[i])   
				min=i;
	
		printf("최솟값은 %d 입니다\n",arr[min]);
	
		swap(temp,arr[min],arr[j-1]);	//교환하는 라인 
	
		printf("%dPASS : ",j);
		for(i=0;i<n;i++)
			printf("%d",arr[i]); 
		printf("\n\n");
	}
}   
