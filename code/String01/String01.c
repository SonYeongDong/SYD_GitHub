#include <stdio.h>
int main(void)
{
	char ch1='A', ch2='B', ch3='C';
	char szData[4]={'A','B','C'};
	char szNewData[4]={"ABC"};
	printf("%s\n" , szNewData);
	printf("%d\n" , szNewData[0]); 
	return 0;
}

