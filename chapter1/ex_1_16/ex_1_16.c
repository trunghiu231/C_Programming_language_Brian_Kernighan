#include <stdio.h>

/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.

Đầu tiên, chương trình cũ thực hiện nhiệm vụ tìm và in ra dòng dài nhất trong các dòng nhập vào.
đồng thời in ra càng nhiều nội dung của dòng đó càng tốt.

Sử đổi chương trình chính của chương trình tìm dòng dài nhất để nó in chính xác độ dài của các
dòng đầu vào tùy ý và càng nhiều văn bản càng tốt.
Giải pháp: sửa lại hàm getline để nó có thể đọc được các dòng dài hơn MAXLINE,
nhưng vẫn chỉ tối ưu MAXLINE-1 ký tự vào mảng để tránh tràn bộ nhớ
 */
#define MAXLINE 1000 /* Mỗi dòng nhập vào lưu tối đa 999 ký tự và 1 ký tự kết thúc */
/*Đọc một dòng từ đầu vào, lưu vào mảng s, trả về độ dài dòng vừa đọc
Nếu dòng dài hơn MAXLINE, chỉ lưu được MAXLINE-1 ký tự */
int getline(char line[], int maxline);
/*Hàm copy sao chép nội dung từ mảng from sang mảng to.*/
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len;               /* lưu độ dài dòng hiện tại */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) // Nếu có ký tự, độ dài dòng > 0, còn có EOF thì getline sẽ trả về 0, nên vòng lặp sẽ dừng lại
    {
        if (len > max) /* Nếu độ dài dòng hiện tại lớn hơn độ dài lớn nhất đã thấy */
        {
            max = len;           /* Cập nhật độ dài lớn nhất */
            copy(longest, line); /* Sao chép nội dung của dòng hiện tại vào mảng longest để lưu lại dòng dài nhất */
        }
    }
    if (max > 0) /* there was a line */
    {
        printf("Longest line length: %d\n", max);
        printf("Content (as much as possible):\n%s", longest);
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
    /* Tiếp tục đọc phần còn lại của dòng (nếu có) để tính đúng độ dài,
       nhưng không lưu vào mảng nữa */
    if (c != '\n' && c != EOF)
    {
        while ((c = getchar()) != EOF && c != '\n')
        {
            ++i; /* tăng độ dài thực tế */
        }
    }
    return i;
}
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}