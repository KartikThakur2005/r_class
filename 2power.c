#include<stdio.h>
int main()
{
     int x=0;
     scanf("%d",&x);

      printf("%d \n",x);
     if((x&(x-1)) ==0)
     {
         printf("yes \n"); 
     }
     else
     {
        printf("no \n");  
     }

     return 0;
}
