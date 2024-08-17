#include<stdio.h>

int main()
{ 
  int i = 11010101;
  int pad = ~(-1 <<4);
  
   int a = i&pad;
   int b = i&(pad<<4);

    int z= a<<4 | b>>4;

    printf("%d \n",z);

  return 0;
}
