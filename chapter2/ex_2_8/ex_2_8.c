#include <stdio.h>
/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.

Viết hàm rightrot(x,n) trả về giá trị của số nguyên x được xoay sang phải n vị trí.
rotated to the right: các bit được dịch sang phải, bit bị đẩy ra bên phải không mất đi mà
sẽ được đưa lại vào bên trái.
*/
unsigned rightrot(unsigned x, int n)
{
    int bits = sizeof(unsigned) * 8;
    n = n % bits;
    if (n == 0)
    {
        return x;
    }

    unsigned right_part = x >> n;         /* Dịch phải n vị trí */
    unsigned left_part = x << (bits - n); /* Dịch trái 1 lượng bit -n */

    return right_part | left_part; /* ghép lại */
}

int main(void)
{
    unsigned int x = 0b10110101; /* 181 = 0xB5 */
    int n = 4;

    printf("x           = 0x%08X = %u\n", x, x);
    printf("rightrot   = 0x%08X = %u\n", rightrot(x, n), rightrot(x, n));

    return 0;
}