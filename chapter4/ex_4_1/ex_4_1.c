#include <stdio.h>

/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
Bài tập 4-1. Viết hàm strindex(s,t) trả về vị trí xuất hiện cuối cùng của t trong s, hoặc -1 nếu không có.
*/

int strindex(char s[], char t[])
{
    int i, j, k;
    int rightmost = -1; // Mặc định là -1 nếu không tìm thấy

    // Duyệt qua từng ký tự của chuỗi s
    for (i = 0; s[i] != '\0'; i++)
    {
        // So khớp chuỗi t bắt đầu từ vị trí i trong s
        // Điều kiện lặp, trong t còn ký tự và s[j] phải khớp với t[k]
        // Nếu khớp, tăng j và k, nếu không khớp thì dừng
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;

        // Nếu k > 0 và t[k] == '\0' nghĩa là đã duyệt hết chuỗi t và tìm thấy 1 lần khớp
        if (k > 0 && t[k] == '\0')
        {
            rightmost = i; // Cập nhật vị trí mới nhất tìm thấy
        }
    }

    return rightmost;
}

int main()
{
    char s[] = "hello world, hello C";
    char t[] = "hello";

    int pos = strindex(s, t);
    if (pos != -1)
        printf("Rightmost occurrence at position: %d\n", pos);
    else
        printf("Not found\n");

    return 0;
}