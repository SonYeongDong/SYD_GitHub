#include <stdio.h>

int main(void)
{
 int jumsu_arr[5];
 
     for (int i = 0; i < 5; i++)
     {
             printf("%d 번째 학생의 성적을 입력하세요.", i+1);
             scanf("%d", &jumsu_arr[i]);
             }
   
    for(int j = 0; j<5; j++)
    {
     if(jumsu_arr[j] >= 90)
               printf("%d 번째 학생은 A 등급 입니다.\n", j+1);
     else if(jumsu_arr[j] >=80 && jumsu_arr[j] <90)
               printf("%d 번째 학생은 B 등급 입니다.\n", j+1);
     else if(jumsu_arr[j] >=70 && jumsu_arr[j] <80)
               printf("%d 번째 학생은 C 등급 입니다.\n", j+1);
     else
         printf("%d 번째 학생은 F 등급 입니다.\n", j+1);
}
   
 return 0;  
}

