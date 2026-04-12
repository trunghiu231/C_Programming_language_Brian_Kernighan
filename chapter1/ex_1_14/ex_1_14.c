#include <stdio.h>

/*Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.
Viết một chương trình để in ra biểu đồ tần suất của các ký tự khác nhau trong đầu vào của nó.
 */
#define MAXCHAR 128 // số ký tự ASCII chuẩn

int main()
{
    int c;
    int freq[MAXCHAR]; //Mảng lưu số lần xuất hiện của mỗ ký tự

    // Khởi tạo mảng tần suất với giá trị 0
    for (size_t i = 0; i < MAXCHAR; ++i)
    {
        freq[i] = 0;
    }

    // Đọc đầu vào bằng getchar() và đếm tần suất của mỗi ký tự
    while ((c = getchar()) != EOF)
    {
        if (c < MAXCHAR)
        {
            ++freq[c]; // Tăng tần suất của ký tự tương ứng khi nhập vào ký tự đó
        }
    }

    // In histogram ngang
    for (size_t i = 0; i < MAXCHAR; ++i)
    {
        if (freq[i] > 0)
        {
            if (i == ' ')
            {
                printf("' ' : ");
            }
            else if (i == '\n')
            {
                printf("\\n  : ");
            }
            else if (i == '\t')
            {
                printf("\\t  : ");
            }
            else
            {
                printf("%c   : ", (char)i);
            }

            for (size_t j = 0; j < freq[i]; ++j) // In ra số lượng '*' tương ứng với tần suất của ký tự
            {
                putchar('*');
            }
            putchar('\n');
        }
    }
    return 0;
}
