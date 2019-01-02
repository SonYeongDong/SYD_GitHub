#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	a=a/10;
	switch(a)
	{
	case 10: 
	 printf("A"); 
	break;
	case 9: 
	 printf("A");  break;
	case 8: 
	 printf("B");  break;
	case 7: 
	 printf("C");  break;		
	case 6: 
	 printf("D");  break;
	case 5: 
	 printf("E");  break;	
	case 4: 
	 printf("E");  break;
	case 3: 
	 printf("E");  break;
	case 2: 
	 printf("E");  break;	
	case 1: 
	 printf("E");  break;	 
	default: 
	 printf("잘못된 입력 값입니다.");  break;
	}
	return 0;
}
