#include <stdio.h>
int main(void)
{
	int x=10, y=20, nTmp=0;        //nTmp는 '교환'을 위해 필요한 변수이다.  
	printf("Before: %d, %d\n", x, y);
	nTmp=x;
	x=y;
	y=nTmp;
	printf("After: %d, %d\n", x, y); //교환이 완료된 것을 확인하기 위해 출력한다.
	return 0; 
}
