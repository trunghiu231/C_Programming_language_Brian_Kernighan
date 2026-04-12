#include <stdio.h>

/*Exercise 1-19. Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.  
Viết hàm reverse(s) đảo ngược chuỗi ký tự s. 
sử dụng hàm reverse(s) để viết chương trình đảo ngược đầu vào theo từng dòng. */
#define MAXLINE 1000 /* Mỗi dòng nhập vào lưu tối đa 999 ký tự và 1 ký tự kết thúc */

/* Hàm tính độ dài của một dòng, và đọc từng dòng vào mảng*/
int getline(char line[], int maxline);
void reverse(char s[], int length); /* Hàm đảo ngược chuỗi ký tự */
/* print the longest input line */
main()
{
    int len;            /* lưu độ dài dòng hiện tại */
    char line[MAXLINE]; /* current input line */
    while ((len = getline(line, MAXLINE)) > 0) // Nếu có ký tự, độ dài dòng > 0, còn có EOF thì getline sẽ trả về 0, nên vòng lặp sẽ dừng lại
    {
        reverse(line, len); /* Đảo ngược dòng vừa đọc */
        printf("%s", line); /* In ra dòng đã đảo ngược */
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
/* reverse: đảo ngược chuỗi s có độ dài length 
i bắt đầu từ đầu chuỗi, j từ cuối chuỗi -1 vì chừa cái '\0' ra, đảo cho nhau*/
void reverse(char s[], int length)
{
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}