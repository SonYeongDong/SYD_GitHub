#include <stdio.h>
int main(void)
{
	int student[100]={0};
	int a, i, j;
	int max=0;
	int min=0;
	printf("�л� ���� �Է��ϼ���(0~100):");
	scanf("%d", &a);
	printf("������ �Է¼���");
	for(i=0; i<a; i++)
		scanf("%d", &student[i]);
		
	for(i=0; i<a; i++)
		if(max<student[i])
			max=student[i];
			
	min=max;
	for(i=0; i<a; i++)
		if(min>student[i])
			min=student[i];
			
	printf("%d���� ���� 1���� %d, �õ��� %d", a, max, min);
	return 0;	
}
