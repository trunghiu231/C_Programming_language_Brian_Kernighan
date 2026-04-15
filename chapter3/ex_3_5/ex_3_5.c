#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.

Bài tập 3-5. Viết hàm itob(n,s,b) chuyển đổi số nguyên n thành dạng biểu diễn ký tự cơ số b
trong chuỗi s. Cụ thể, itob(n,s,b) định dạng s thành một số nguyên thập lục phân trong s.
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

/* itob: chuyển số nguyên n thành chuỗi ở cơ số b */
void itob(int n, char s[], int b)
{
    int i = 0;
    unsigned int m;

    if (n < 0)
        m = -(unsigned int)n; // tránh tràn với INT_MIN
    else
        m = n;
        
    do
    {
        int digit = m % b;
        if (digit < 10)
            s[i++] = digit + '0'; // chữ số 0–9
        else
            s[i++] = digit - 10 + 'A'; // chữ cái A–Z cho 10–35
    } while ((m /= b) > 0);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
int main() {
    char buf[100];

    itob(255, buf, 2);
    printf("255 in bin: %s\n", buf);   // 11111111

    itob(245, buf, 8);
    printf("255 in oct: %s\n", buf);   // 377

    itob(255, buf, 10);
    printf("255 in dec: %s\n", buf);  // 255

    itob(255, buf, 16);
    printf("255 in hex: %s\n", buf);  // FF

    itob(-255, buf, 16);
    printf("-255 in hex: %s\n", buf); // -FF

    return 0;
}
