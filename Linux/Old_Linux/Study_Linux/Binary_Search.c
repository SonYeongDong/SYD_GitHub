#include <stdio.h>


int Bsear(int Bsear_arr[], int Barr_length, int Binput)
{
	int min = 0;
	int max = Barr_length -1;
	int medi;
	
	while(min <= max)
	{
		medi = (min + max) / 2;
		
		if(Bsear_arr[medi] > Binput)
		{
			max = medi - 1;
		}

		else if(Bsear_arr[medi] < Binput)
		{
			min = medi + 1;
		}
		
		else
		{
			return medi;
		}	
	}
	return -1;
} 


int main(void)
{
	int sear_arr[] = {1, 3, 4, 7, 10, 12, 15, 18};
	int arr_length = sizeof sear_arr / sizeof sear_arr[0];
	int input, result; 	

	printf("Binary_Search\n\n");
	printf("Please enter a number\n");
	printf("Output 1 if matches the number in the program\n");
	printf("Otherwise, 0 is output\n");
	scanf("%d", &input);
	
	result = Bsear(sear_arr, arr_length, input);
	
	if(result != -1)
	{
		printf("1\n");
	}

	else
	{
		printf("0\n");
	}	

	return 0;
}
