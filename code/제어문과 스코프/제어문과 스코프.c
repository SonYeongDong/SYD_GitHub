#include <stdio.h>
main()
{
	int nInput=0;
	scanf("%d", &nInput);
	
	if (nInput>10)
	{
		int nInput=20;
		printf("%d\n", nInput);
		if (nInput<30)
		{
			int nInput=30;
			printf("%d\n", nInput);
		}
	}
	printf("%d\n", nInput);
}

