#include <stdio.h>
int main(void)
{
	int student[100]={0};
	int a, i, j;
	int max=0;
	int min=0;
	printf("학생 수를 입력하세요(0~100):");
	scanf("%d", &a);
	printf("점수를 입력세요");
	for(i=0; i<a; i++)
		scanf("%d", &student[i]);
		
	for(i=0; i<a; i++)
		if(max<student[i])
			max=student[i];
			
	min=max;
	for(i=0; i<a; i++)
		if(min>student[i])
			min=student[i];
			
	printf("%d명은 중의 1등은 %d, 꼴등은 %d", a, max, min);
	return 0;	
}
