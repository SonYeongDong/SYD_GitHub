#include <stdio.h>
main()
{
	int nResult, w=0, x=-1, y=-1, z=1;
	nResult=w++||x++&&++y||++z;
	printf("%d %d %d %d %d\n", w, x, y, z, nResult);	
}
