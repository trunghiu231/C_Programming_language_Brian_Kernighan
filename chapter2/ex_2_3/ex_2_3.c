#include <stdio.h>
/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.

Viết một hàm htoi(s), chuyển đổi một chuỗi các chữ số thập lục phân (bao gồm tùy chọn 0x hoặc 0X)
thành giá trị nguyên tương đương của nó. Các chữ số cho phép là 0 đến 9, a đến f và A đến F.
Công thức chuyển đổi chung: n = cơ số * n + digit
ví dụ - htoi("1A") = 16 * 0 + 1 = 1, sau đó n = 16 * 1 + 10 = 26
hoặc 0123
n = 0
n = 8 * 0 + 1 = 1
n = 8 * 1 + 2 = 10
n = 8 * 10 + 3 = 83
*/
int htoi(char s[]);
int main()
{
    char hex1[] = "0x1A";
    char hex2[] = "1a";
    char hex3[] = "0XFF";
    char hex4[] = "123";

    printf("%s -> %d\n", hex1, htoi(hex1)); // 26
    printf("%s -> %d\n", hex2, htoi(hex2)); // 26
    printf("%s -> %d\n", hex3, htoi(hex3)); // 255
    printf("%s -> %d\n", hex4, htoi(hex4)); // 291
}

int htoi(char s[])
{
    int i = 0, n = 0;

    // Bỏ qua tiền tố 0x hoặc 0X nếu có
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }

    for (; s[i] != '\0'; i++)
    {
        int digit;
        if (s[i] >= '0' && s[i] <= '9')
        {
            digit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            digit = s[i] - 'a' + 10; // ví dụ a[i] = 'c' thì digit = 'c' - 'a' + 10 = 2 + 10 = 12
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            digit = s[i] - 'A' + 10; // ví dụ a[i] = 'F' thì digit = 'F' - 'A' + 10 = 5 + 10 = 15
        }
        else
        {
            break; // ký tự không hợp lệ
        }
        n = 16 * n + digit;
    }
    return n;
}