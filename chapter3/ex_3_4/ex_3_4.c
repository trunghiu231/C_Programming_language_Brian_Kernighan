#include <stdio.h>
#include <string.h>
#include <limits.h> // để lấy giá trị INT_MIN
// void itoa(int n, char s[])
// {
//     int i, sign;
//     if ((sign = n) < 0) /* ghi lại dấu của n */
//         n = -n;         /* đổi sang số dương để dễ xử lý */
//     i = 0;
//     do
//     {                          /* tạo các chữ số theo thứ tự ngược */
//         s[i++] = n % 10 + '0'; /* lấy chữ số cuối cùng và chuyển thành ký tự */
//     } while ((n /= 10) > 0); /* bỏ chữ số cuối cùng, lặp lại cho đến khi n = 0 */
//     if (sign < 0)
//         s[i++] = '-'; /* nếu ban đầu là số âm thì thêm dấu '-' */
//     s[i] = '\0';      /* kết thúc chuỗi bằng ký tự null */
//     reverse(s);       /* đảo ngược chuỗi để có thứ tự đúng */
// }
/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.

Bài tập 3-4. Trong biểu diễn số bù hai, phiên bản itoa của chúng ta không xử lý được số âm lớn nhất,
tức là giá trị của n bằng -(2wordsize-1). Hãy giải thích tại sao không.
Hãy sửa đổi nó để in giá trị đó một cách chính xác, bất kể máy nào chạy nó.

Giải thích: Trong biểu diễn số bù hai, số ân lớn nhất là -(2^(wordsize-1)) có giá trị
tuyệt đối lớn hơn số dương lớn nhất (2^(wordsize-1) - 1). Nếu mình cố gắng chuyển đổi sang
số dương bằng cách lấy đối của nó thì tràn số (overflow) sẽ xảy ra vì không có đủ bit
để biểu diễn giá trị dương tương ứng. Do đó, itoa không thể xử lý được số âm lớn nhất này.
*/

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
/* itoa: chuyển số nguyên n thành chuỗi trong s */
void itoa(int n, char s[])
{
    int i = 0;
    unsigned int m; // dùng unsigned để tránh tràn

    if (n < 0)
    {
        m = -(unsigned int)n; // chuyển sang unsigned rồi đổi dấu
    }
    else
    {
        m = n;
    }
    do
    {
        s[i++] = m % 10 + '0'; // lấy chữ số cuối
    } while ((m /= 10) > 0);

    if (n < 0)
    {
        s[i++] = '-'; // thêm dấu âm nếu cần
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[100];
    int n = INT_MIN; // Số âm lớn nhất trong int (32-bit)
    itoa(n, s);
    printf("The string representation of %d is: %s\n", n, s);
    return 0;
}