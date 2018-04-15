#include <stdio.h>
main()
{
	int input, i=31;
	scanf("%d", &input);
	while(i>=0)
	{
		printf("%d", input>>i&1);
		i--;
	}
}
