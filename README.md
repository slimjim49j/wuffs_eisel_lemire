# Wuffs Float Parser

This is a slimmed down version of the `wuffs` library for using its float parser function.

It contains an implementation of the Eisel-Lemire float parsing algorithm.

## More info:

https://github.com/google/wuffs

https://nigeltao.github.io/blog/2020/eisel-lemire.html

## Usage:

Using the wrapper function:

```c
#include "wuffs_eisel_lemire.c"
#include <stdio.h>

int main()
{
 uint8_t *ptr = (uint8_t *)"3.14159e100";
 int len = sizeof("3.14159e100")-1;
 double my_double;
 if (wuffs_double_from_str(ptr, len, &my_double))
 {
  printf("Good");
 }
 return 0;
}
```

Using the original api:

```c
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
```
