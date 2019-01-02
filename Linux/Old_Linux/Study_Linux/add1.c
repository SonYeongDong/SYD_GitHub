#include <stdio.h>
int add(int sum);

int main(void)
{
	int ad1 = 10;
	int ad2;
	printf("1부터 10까지 더한 결과는\n");
	ad2 = add(ad1);
	printf("%d입니다.", ad2);
	return 0;
}

