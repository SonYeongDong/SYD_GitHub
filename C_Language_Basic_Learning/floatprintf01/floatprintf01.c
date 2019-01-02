#include<stdio.h>
int main(void)
{
	printf("%d\n", sizeof(123.456F0));
	printf("%d\n", sizeof(123.456));
	
	printf("%f\n",123.456f);
	printf("%1f\n",123.456);
	printf("%f\n",123.456);
	
	return 0;
}
