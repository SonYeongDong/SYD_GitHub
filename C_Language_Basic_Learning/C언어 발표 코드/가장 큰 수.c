#include <stdio.h>
int main(void)
{
	int i, m=0, n=0;
	int vrt[10];
	printf("10개의 자연수를 입력하세요\n");
	for(i=0; i<10; i++){
		scanf("%d", &vrt[i]);
	}
		for(i=0; i<10; i++){
		if(vrt[i]%2==0){
			if(vrt[i]>m)
				m=vrt[i];
			}
		else
			if(vrt[i]>n)
				n=vrt[i];
		}
		if(m>0)
		printf("가장 큰 짝수는 %d입니다", m);
		if(n>0)
		printf("가장 큰 홀수는 %d입니다", n);	
}
