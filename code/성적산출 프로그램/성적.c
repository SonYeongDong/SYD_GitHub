#include <stdio.h>

int main(void)
{
 int jumsu_arr[5];
 
     for (int i = 0; i < 5; i++)
     {
             printf("%d ��° �л��� ������ �Է��ϼ���.", i+1);
             scanf("%d", &jumsu_arr[i]);
             }
   
    for(int j = 0; j<5; j++)
    {
     if(jumsu_arr[j] >= 90)
               printf("%d ��° �л��� A ��� �Դϴ�.\n", j+1);
     else if(jumsu_arr[j] >=80 && jumsu_arr[j] <90)
               printf("%d ��° �л��� B ��� �Դϴ�.\n", j+1);
     else if(jumsu_arr[j] >=70 && jumsu_arr[j] <80)
               printf("%d ��° �л��� C ��� �Դϴ�.\n", j+1);
     else
         printf("%d ��° �л��� F ��� �Դϴ�.\n", j+1);
}
   
 return 0;  
}

