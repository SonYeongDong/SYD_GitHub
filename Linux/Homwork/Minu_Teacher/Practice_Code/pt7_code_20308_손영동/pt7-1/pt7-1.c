#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	int num, i, sum, mul;
	
	printf("Input a number please : ");
	scanf("%d", &num);
	
	pid  = fork();
	
	if(pid > 0)
	{
		for(i = 1, sum  = 0; i <= num; i++)
		sum = sum + i;
		printf("Sum is %d\n", sum);
	}
	
	else
	{
		for(i = 1, mul = 1; i <= num; i++)
		mul  = mul * i;
		printf("mul is %d\n", mul);
	}

	return 0;
}
