#include <stdio.h>

int main(void)
{
	int select;
	
	printf("������ �˰� ���� ������ �����Ͻʽÿ�.\n");
	printf("1.�Ϻ���\n2.���̽�ũ��\n3.����Ʈ\n");
	scanf("%d", &select);
	switch(select)
	{
	case 1 :
		printf("5000���Դϴ�.\n");
		break; 
	case 2 :
		printf("3000���Դϴ�.\n");
		break; 
	case 3 :
		printf("4000���Դϴ�.\n");
		break; 
	default:
		printf("�߸��� �Է��Դϴ�.\n");
		
	}
	return 0;	
}
