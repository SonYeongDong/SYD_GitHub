#include<stdio.h>
int main(void)
{
	int nAge;
	char name[5];
	printf("���̸� �Է��ϼ���: ");
	scanf("%d", &nAge);
	printf("�̸��� �Է��ϼ���: ");
	scanf("%s", name);
	printf("����� ���̴� %d�̰� �̸��� %s�Դϴ�.\n",nAge,name);
	return 0;
}
