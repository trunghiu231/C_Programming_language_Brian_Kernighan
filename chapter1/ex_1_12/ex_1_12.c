#include <stdio.h>

/*Exercise 1-12. Write a program that prints its input one word per line.
 */

#define IN 1
#define OUT 0

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t') //Nếu là khoảng trắng, xuống dòng or tab
        {
            if (state == IN) // Nếu đang trong một từ, chứ 2 cái tab thì ko phải xuống dòng 2 lần
            {
                putchar('\n'); // kết thúc một từ
                state = OUT;
            }
        }
        else
        {
            putchar(c); // in ký tự của từ
            state = IN;
        }
    }
    return 0;
}
