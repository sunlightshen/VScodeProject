#include <stdio.h>

const int MAX = 3;

int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* 指针中第一个元素的地址 */
   ptr = var;
   i = 0;
   //判断是否到达最大地址位置，而且数组对应的地址都是相互连续的。
   while ( ptr <= &var[MAX - 1] )
   {

      printf("Address of var[%d] = %x\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* 指向上一个位置 */
      ptr++;
      i++;
   }
   return 0;
}