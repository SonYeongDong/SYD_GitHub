#include <stdio.h>
int main(void)
{
	int nInput, nTotal=0;
	scanf("%d", &nInput);
	nTotal+=nInput;
	scanf("%d", &nInput);
	nTotal+=nInput;
	scanf("%d", &nInput);
	nTotal+=nInput;
	printf("Total : %d\n", nTotal);
	return 0; 
}

