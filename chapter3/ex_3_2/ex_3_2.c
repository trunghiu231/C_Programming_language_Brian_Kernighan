#include <stdio.h>
// /* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
// int binsearch(int x, int v[], int n)
// {
//     int low, high, mid;
//     low = 0;
//     high = n - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (x < v[mid])
//             high = mid + 1;
//         else if (x > v[mid])
//             low = mid + 1;
//         else /* found match */
//             return mid;
//     }
//     return -1; /* no match */
// }
/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.

Bài tập 3-2. Viết một hàm escape(s,t) chuyển đổi các ký tự như xuống dòng và tab thành các chuỗi thoát
có thể nhìn thấy như \n và \t khi sao chép chuỗi t vào s. Sử dụng câu lệnh switch.
Viết một hàm cho chiều ngược lại, chuyển đổi các chuỗi thoát thành các ký tự thực.
*/
void escape(const char t[], char s[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(const char t[], char s[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        if (t[i] == '\\')
        {
            switch (t[++i])
            {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = t[i];
                break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char t[] = "Hello\tWorld\nThis is a test.";
    char s[100];
    char u[100];

    escape(t, s);
    printf("Escaped: %s\n", s);

    unescape(s, u);
    printf("Unescaped: %s\n", u);

    return 0;
}