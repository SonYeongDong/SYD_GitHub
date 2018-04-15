#include<stdio.h>
int main(void)
{
	char szBuffer[32];
	
	gets(szBuffer);
	printf("%s\n", szBuffer);
	return 0;
}
