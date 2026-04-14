#include <stdio.h>
/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.

Bài tập 2-9. Trong hệ thống số bù hai, x &= (x-1) xóa bit 1 bên phải nhất trong x.
Giải thích tại sao. Sử dụng quan sát này để viết một phiên bản nhanh hơn của bitcount.

x  = 101100 (44)
x-1= 101011 (43)
x&(x-1) = 101000 (40)


Trong hệ thống số bù 2 (two’s complement), khi ta lấy x-1, tất cả các bit 0 bên phải
của bit 1 cuối cùng sẽ trở thành 1, và bit 1 cuối cùng đó sẽ thành 0.
Khi thực hiện phép AND giữa x và x-1, bit 1 bên phải nhất trong x bị xóa, vì nó
thành 0 trong x-1, và phép AND sẽ cho kết quả 0.

Tức là mỗi lần thực hiện x &= (x-1), ta sẽ xóa đi một bit 1 trong x. 
Do đó, số lần thực hiện phép này cho đến khi x trở thành 0 sẽ bằng số lượng bit 1 trong x.

bitcount:  count 1 bits in x
   int bitcount(unsigned x)
   {
       int b;
       for (b = 0; x != 0; x >>= 1)
           if (x & 01)
               b++;
       return b;
   }
*/

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int bitcount_fast(unsigned x)
{
    int count;
    /* Mỗi lần thực hiện x &= (x-1), ta xóa đi một bit 1 trong x. \
    Do đó, số lần thực hiện phép này cho đến khi x trở thành 0 sẽ bằng số lượng bit 1 trong x.
    */
    for (count = 0; x != 0; x &= (x - 1))
    {
        count++;
    }
    return count;
}

int main()
{
    unsigned x = 0b101100; /* 44 */
    printf("%u\n", bitcount(x));
    printf("%u\n", bitcount_fast(x));

    return 0;
}