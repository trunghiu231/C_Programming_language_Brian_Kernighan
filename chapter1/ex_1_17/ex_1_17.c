#include <stdio.h>

/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.  
Viết chương trình in ra tất cả các dòng đầu vào có độ dài lớn hơn 80 ký tự*/
#define MAXLINE 1000
#define THRESHOLD 80 /* Độ dài ngưỡng để in ra các dòng dài hơn */

/* Hàm tính độ dài của một dòng*/
int getline(char line[], int maxline);


/* print the longest input line */
main()
{
    int len;            /* lưu độ dài dòng hiện tại */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0) // Nếu có ký tự, độ dài dòng > 0, còn có EOF thì getline sẽ trả về 0, nên vòng lặp sẽ dừng lại
    {
        if (len > THRESHOLD) /* Nếu độ dài dòng hiện tại lớn hơn ngưỡng */
        {
            printf("%s", line); /* In ra dòng đó */
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
