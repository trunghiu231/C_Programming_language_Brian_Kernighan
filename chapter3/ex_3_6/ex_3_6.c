#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third 
argument is a minimum field width; the converted number must be padded with blanks on the 
left if necessary to make it wide enough. 

Bài tập 3-6. Viết một phiên bản của itoa chấp nhận ba đối số thay vì hai. 
Đối số thứ ba là chiều rộng tối thiểu của trường; số được chuyển đổi 
phải được thêm khoảng trắng vào bên trái nếu cần thiết để làm cho nó đủ rộng.
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

void itoa(int n, char s[], int w) {
    int i = 0;
    unsigned int m;

    if (n < 0)
        m = -(unsigned int)n;   // tránh tràn với INT_MIN
    else
        m = n;

    do {
        s[i++] = m % 10 + '0';
    } while ((m /= 10) > 0);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);

    // thêm khoảng trắng nếu cần
    int len = strlen(s);
    if (len < w) {
        // dịch chuỗi sang phải
        memmove(s + (w - len), s, len + 1); // +1 để dịch cả '\0'
        for (int j = 0; j < w - len; j++)
            s[j] = ' ';
    }
}

int main()
{
    char buf[100];

    itoa(123, buf, 10);
    printf("%s\n", buf); //        123

    itoa(-456, buf, 10);
    printf("%s\n", buf); //       -456

    itoa(7890, buf, 5);
    printf("%s\n", buf); //  7890

    itoa(-2147483648, buf, 15);
    printf("%s\n", buf); //  -2147483648
    
    return 0;
}