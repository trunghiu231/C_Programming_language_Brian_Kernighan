#include <stdio.h>
/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.  

Viết hàm invert(x,p,n) trả về x với n bit bắt đầu từ vị trí p được đảo ngược 
(tức là 1 thành 0 và ngược lại), giữ nguyên các bit còn lại.
*/
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~(~0u << n) << (p - n + 1); /* tạo mask với n bit 1 tại vị trí p */
    return x ^ mask; /* XOR x với mask để đảo n bit tại vị trí p */
}

int main(){
    unsigned x = 0xAD; /* 1010 1101 */
    int p = 4, n = 3;

    unsigned result = invert(x, p, n);

    printf("x      = %08X (%u)\n", x, x);
    printf("p=%d, n=%d\n", p, n);
    printf("result = %08X (%u)\n", result, result);
    return 0;
}