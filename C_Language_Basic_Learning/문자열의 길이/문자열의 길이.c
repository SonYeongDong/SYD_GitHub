#include <stdio.h>
main()
{
	char szBuffer[32]={0};
	int nLength=0;
	printf("Input your name : ");
	gets(szBuffer);
	
	while(szBuffer[nLength]!='\0')
		nLength++;
	printf("Your name is %s(%d). \n", szBuffer, nLength);
}
