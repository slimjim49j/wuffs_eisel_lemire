#include "wuffs_eisel_lemire.c"
#include <stdio.h>

int main()
{
 uint8_t *ptr = (uint8_t *)"3.14159e100 abc";
 int len = sizeof("3.14159e100 abc")-1;
 double my_double;
 if (wuffs_double_from_str(ptr, len, &my_double))
 {
  printf("Good");
 }
 return 0;
}