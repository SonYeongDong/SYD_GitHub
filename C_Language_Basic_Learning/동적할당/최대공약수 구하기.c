#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, temp=0;
	int i, j, k;
	printf("�� �ڿ����� �Է��ϼ���.");
	scanf("%d %d",&a, &b);
	//printf("%d�� %d�� �ִ�����\n",a, b);
	int * num1 = 0;//A ����� ���� 
	int * num2 = 0;//B ����� ����  //A 13 B 17 => NUM1 13 NUM2 17;
	int * num3 = 0;//A�� B�� ����� ���� 
	int index = 0;
	int length1=0, length2=0, length3=0;
	
	num1 = (int*)malloc(sizeof(int)*a);
	num2 = (int*)malloc(sizeof(int)*b);
	num3 = (int*)malloc(sizeof(int)* (a>b? a:b));
	
	for(i=1; i<=a; i++)
	{
		if(a%i==0)
		{
			num1[index++]=i;
			//printf("num1 = %d\n",num1[index-1]);
		}
	}
	length1=index;
	//printf("%d�� %d�� ������� length1 = %d\n",a, b,length1);
	
	index = 0;
	
	for(i=1; i<=b; i++)
	{
		if(b%i==0)
		{
			num2[index++]=i;
			//printf("num2 = %d\n",num2[index-1]);
		}
	}
	length2=index;
	//printf("%d�� %d�� ������� length2 = %d\n",a, b,length2);

	index = 0;

	for(i=1; i<length1; i++)	
	{
		for(j=1; j<length2; j++)
		{
			if(num1[i]==num2[j])
			{
				num3[index++] = num1[i];
				//printf("num3 = %d\n",num3[index-1]);
			}		
		}
	}
	length3 = index;
	//printf("%d�� %d�� �ִ�����\n",a, b);

	temp =  num3[0];
	
	for(i=1; i<=length3; i++)
	{
		//printf("temp = %d / num3 = %d\n",temp,num3[i]);
		temp = temp < num3[i] ? num3[i] : temp;
	}

	printf("%d��(��) %d�� �ִ�����\n",a, b);
	printf("%d", temp);
}
