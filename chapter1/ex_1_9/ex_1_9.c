#include <stdio.h>
#include <stdbool.h>

/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
    Viết chương trình để sao chép đầu vào của nó thành đầu ra, thay thế mỗi chuỗi một hoặc
nhiều khoảng trắng bằng một khoảng trắng đơn. */

int main()
{

    int c;
    bool lastWasBlank = false;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (lastWasBlank == false)
            {
                putchar(c);
                lastWasBlank = true;
            }
        }
        else
        {
            putchar(c);
            lastWasBlank = false;
        }
    }

    return 0;
}
