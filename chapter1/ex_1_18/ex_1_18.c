#include <stdio.h>

/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
Viết chương trình để loại bỏ các khoảng trắng và tab ở cuối mỗi dòng đầu vào,
và xóa hoàn toàn các dòng trống. */
#define MAXLINE 1000 /* Mỗi dòng nhập vào lưu tối đa 999 ký tự và 1 ký tự kết thúc */

/* Hàm tính độ dài của một dòng, và đọc từng dòng vào mảng*/
int getline(char line[], int maxline);

void trim(char s[]); /* Hàm loại bỏ khoảng trắng và tab ở cuối dòng */
/* print the longest input line */
main()
{
    int len;            /* lưu độ dài dòng hiện tại */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0) // Nếu có ký tự, độ dài dòng > 0, còn có EOF thì getline sẽ trả về 0, nên vòng lặp sẽ dừng lại
    {
        trim(line); /* Loại bỏ khoảng trắng và tab ở cuối dòng */
        if (line[0] != '\0') /* Nếu dòng không phải là dòng trống sau khi đã trim */
        {
            printf("%s\n", line); /* In ra dòng đã được trim */
        }

    }
    return 0;
}

/* getline:  read a line into s, return length  */
int getline(char s[], int lim)
{
    int c, i;
    // còn chỗ chứa trong mảng cho '\0', dùng nếu hết dữ liệu hoặc gặp '\n'
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c; // lưu ký tự vào mảng s tại vị trí i
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void trim(char s[])
{
    int  i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    i--;
    while(i>=0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
    {
        s[i] = '\0';
        i--;
    }
}