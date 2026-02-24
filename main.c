#include "wuffs_eisel_lemire.c"
#include <stdio.h>

int main()
{
 uint8_t *Ptr = (uint8_t *)"3.14159e100";
 int Len = sizeof("3.14159e100")-1;
 wuffs_base__slice_u8 Slice = {.ptr = Ptr, .len = Len};
 wuffs_base__result_f64 Res = wuffs_base__parse_number_f64(Slice, 0);
 if (wuffs_base__status__is_ok(&Res.status) && 3.14159e100 == Res.value)
 {
  printf("Good");
 }
 return 0;
}