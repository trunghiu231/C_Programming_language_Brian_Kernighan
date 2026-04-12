#include <stdio.h>

/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

Viết chương trình detab thay thế các tab trong đầu vào bằng số lượng khoảng trắng ' 'để căn chỉnh
đến tab stop tiếp theo. Giả sử một tập hợp tab stop cố định, ví dụ mỗi n cột.
n nên là 1 biến hay là một tham số biểu tượng?

TABSTOP là những vị trí cột cố định trên màn hình hoặc trong văn bản mà 
con trỏ sẽ nhảy đến khi gặp ký tự tab. Tab không phải là 1 số lượng khoảng
trắng cố định mà nó sẽ nhảy đến tab stop tiếp theo.
với TABSTOP =8, con trỏ ở cột 2 gặp tab nhảy đến cột 8
con trở ở cột 3 gặp tab nhảy đến cột 8
con trở ở cột 8 gặp tab nhảy đến cột 16 
*/

#define TABSTOP 8/* Khoảng cách giữa các tab stop */

int main()
{
    int c, pos = 0; /* pos theo dõi vị trí hiện tại trên dòng */

    while ((c = getchar()) != EOF)
    {
        if (c != '\t') // không gặp tab thì cứ in ra
        {
            putchar(c); /* In ra ký tự nếu không phải là tab */
            pos++;      /* Tăng vị trí hiện tại */
            if (c == '\n')
            {
                pos = 0;
            }
        }
        else
        {
            /* Tính số khoảng trắng cần chèn
                pos % TABSTOP  ra được lượng ký tự từ tab stop trước đến pos hiện tại
                lấy TABSTOP trừ đi số lượng đó để được số khoảng trắng cần chèn */
            int spaces = TABSTOP - (pos % TABSTOP); 
            for (int i = 0; i < spaces; i++)
            {
                putchar(' '); /* In ra khoảng trắng */
            }
            pos += spaces; /* Cập nhật vị trí sau khi chèn khoảng trắng */
        }
    }
    return 0;
}