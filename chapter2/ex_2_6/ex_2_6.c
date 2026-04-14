#include <stdio.h>
/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
position p set to the rightmost n bits of y, leaving the other bits unchanged.

Bài tập 2-6. Viết hàm setbits(x,p,n,y) trả về x với n bit bắt đầu từ vị trí p được 
đặt thành n bit ngoài cùng bên phải của y, giữ nguyên các bit còn lại.

Tóm tắt đề bài: cho x, p, n, y, — lấy n bit phải nhất của y, 
đặt chúng vào x bắt đầu từ vị trí p (tính từ 0 bên phải), các bit còn lại của x giữ nguyên.
*/

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /* mask: n bit toàn 1, ví dụ n=3 → 0b111 
        ~0: tạo số nguyên không dấu với tất cả các bit là 1 
        << n: dịch sang trái n vị trí => đẩy n bit 0 vào bên phải
        ~(~0u << n): Đảo ngược lại kết quả trên, có đc n bit toàn 1 */
    unsigned mask = ~(~0u << n);

    /* lấy n bit phải nhất của y, dịch lên đúng vị trí p 
    y & mask: lấy n bit phải nhất của y 
    vị trí:  7  6  5  4  3  2  1  0
                      [  vùng n=3 bit  ]
                      4  3  2
                            ^
                            p - n + 1 = 2  (đáy của vùng)
    << (p - n + 1): sô lần dịch = vị trí trái nhất của vùng (4) - số bit (3) + 1
    Ví dụ: n bit toàn 1, */
    unsigned y_bits = (y & mask) << (p - n + 1);

    /* tạo mask để xóa n bit tại vị trí p trong x 
    dùng mask đã tạo, dịch sang trái (p - n + 1) lần.
    Ví dụ mask = 0b00000111 (3 bit 1). mask << 2 → 0b00011100 (3 bit 1 ở vị trí 4,3,2)
    Đảo bit của mask để có được mask xóa 
    clear_mask = 0b11100011*/
    unsigned clear_mask = ~(mask << (p - n + 1));

    /* xóa n bit cũ của x rồi đặt bit mới của y vào 
    x & clear_mask: xóa n bit tại vị trí p. x & 0b11100011 → giữ nguyên bit 7,6,1,0 của x, xóa bit 4,3,2
    | y_bits: đặt n bit mới của y vào vị trí p */
    return (x & clear_mask) | y_bits;
}

int main()
{
    unsigned x = 0xAD; /* 1010 1101 */
    unsigned y = 0x06; /* 0000 0110 → 3 bit phải là 1 1 0 */
    int p = 4, n = 3;

    unsigned result = setbits(x, p, n, y);

    printf("x      = %08X (%u)\n", x, x);
    printf("y      = %08X (%u)\n", y, y);
    printf("p=%d, n=%d\n", p, n);
    printf("result = %08X (%u)\n", result, result);
    return 0;
}
