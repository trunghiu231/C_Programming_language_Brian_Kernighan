#include <stdio.h>

/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
In ra biểu đồ tuần xuất độ dài của các từ trong đầu vào 
 */

#define IN 1
#define OUT 0
#define MAXWORD 20 // tối đa độ dài của một từ

int main()
{
    int c, state, length;
    int wordlen[MAXWORD + 1];
    int i, j;

    state = OUT;
    length = 0;
    for (i = 0; i <= MAXWORD; ++i)
        wordlen[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t') // Nếu là khoảng trắng, xuống dòng or tab
        {
            if (state == IN)           // Nếu đang trong một từ
            {                          
                if (length <= MAXWORD) // Nếu độ dài của từ không vượt quá MAXWORD
                    ++wordlen[length]; // tăng số lượng từ có độ dài tương ứng
                length = 0;            // Kết thúc một từ, reset độ dài về 0
                state = OUT;
            }
        }
        else    //Nếu không phải là khoảng trắng, xuống dòng or tab, tức là 1 ký tự
        {
            state = IN; //Đây là trong 1 tự, nên set state = IN
            ++length; //tăng độ dài của từ hiện tại lên 1 đơn vị
        }
    }

    for (i = 1; i <= MAXWORD; ++i)
    {
        printf("%2d: ", i);
        for (j = 0; j < wordlen[i]; ++j)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}