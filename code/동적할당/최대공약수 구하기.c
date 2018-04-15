#include <stdio.h>
#include <stdlib.h>

main()
{
	int a, b, temp=0;
	int i, j, k;
	printf("두 자연수를 입력하세요.");
	scanf("%d %d",&a, &b);
	//printf("%d와 %d의 최대공약수\n",a, b);
	int * num1 = 0;//A 약수를 저장 
	int * num2 = 0;//B 약수를 저장  //A 13 B 17 => NUM1 13 NUM2 17;
	int * num3 = 0;//A와 B의 공약수 저장 
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
	//printf("%d와 %d의 약수개수 length1 = %d\n",a, b,length1);
	
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
	//printf("%d와 %d의 약수개수 length2 = %d\n",a, b,length2);

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
	//printf("%d와 %d의 최대공약수\n",a, b);

	temp =  num3[0];
	
	for(i=1; i<=length3; i++)
	{
		//printf("temp = %d / num3 = %d\n",temp,num3[i]);
		temp = temp < num3[i] ? num3[i] : temp;
	}

	printf("%d과(와) %d의 최대공약수\n",a, b);
	printf("%d", temp);
}
