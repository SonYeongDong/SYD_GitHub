#include<stdio.h>
#include<windows.h>
main()
{
	int n[5][5]={0};
	int i, j, a, b;
	while(1)
	{
		for(i=0; i<5;i++)
			{
				for(j=0;j<5;j++)
				printf("%d", n[i][j]);
				printf("\n");
			}
		
		printf("------------------------------------------------------------------\n"); 
		printf("When you input the desired coordinate value, the part changes to 1\nEntering -2 -2 initializes the coordinate value\n-1 Enter -1 to end the program\n");
		printf("------------------------------------------------------------------\n");
			scanf("%d %d", &a, &b);
			if(a==-1&&b==-1)
			{
				break;
			} 
			else if(a==-2&&b==-2)
			{
				for(i=0; i<5;i++)
					{
						for(j=0;j<5;j++)
							n[i][j]=0;
					}	
			}
			else if(a>=0&&a<6&&b>=0&&b<6)
			{
				n[a][b] = 1;	
			}
			else
			{
				printf("Invalid input value\nPlease re-enter");
				Sleep(1000);
			}
			system("cls");
		}	
	}
