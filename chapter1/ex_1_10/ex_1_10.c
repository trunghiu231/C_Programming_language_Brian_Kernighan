#include <stdio.h>

/*Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.
Viết 1 chương trình để sao chép đầu vào của nó thành đầu ra, thay thế mỗi dấu tab bằng \t,
mỗi backspace bằng \b và mỗi backslash(gạch chéo ngược) bằng \\. Điều này làm cho các tab và backspace
hiển thị theo cách rõ ràng.
*/

int main()
{

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}
