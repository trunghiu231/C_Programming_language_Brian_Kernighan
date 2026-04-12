#include <stdio.h>

/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

Viết chương trình entab thay thế các chuỗi khoảng trắng bằng số lượng tab và khoảng trắng
tối thiểu để đạt được cùng một khoảng cách. Sử dụng cùng một tab stop như trong detab.
Khi một tab hoặc một khoảng trắng đơn sẽ đủ để đạt đến một tab stop, cái nào nên được ưu tiên?
*/
#define TABSTOP 8

int main()
{
    int c;
    int pos = 0;         // vị trí cột hiện tại
    int space_count = 0; // số khoảng trắng liên tiếp

    while ((c = getchar()) != EOF)
    {
        if (c == ' ') //Nếu gặp space
        {
            space_count++;
            pos++;
            if (pos % TABSTOP == 0) //Khi số space đủ để đến tab stop tiếp theo
            {
                putchar('\t');   // thay bằng tab
                space_count = 0; // reset
            }
        }
        else
        {
            // in ra các khoảng trắng dư thừa trước ký tự thường
            while (space_count > 0)
            {
                putchar(' ');
                space_count--;
            }
            putchar(c);
            pos++;
            if (c == '\n')
            {
                pos = 0; // reset về đầu dòng
            }
        }
    }
    return 0;
}
