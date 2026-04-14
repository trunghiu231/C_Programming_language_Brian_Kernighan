#include <stdio.h>
/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
Bài tập 2-4. Viết một phiên bản khác của squeeze(s1,s2) để xóa mỗi ký tự trong s1
khớp với bất kỳ ký tự nào trong chuỗi s2.
*/

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i = k = 0; s1[i] != '\0'; i++)
    {
        // kiểm tra s1[i] có nằm trong s2 không
        // Nếu có thì thoát khỏi vòng lặp, nếu không thì j sẽ chạy đến hết s2 và s2[j] sẽ là '\0'
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; j++)
        {
            ;
        }
        if (s2[j] == '\0') // không tìm thấy s1[i] trong s2, nên giữ lại ký tự này
        {
            s1[k++] = s1[i]; //gán giá trị của s1[i] vào s1[k] rồi tăng k lên 1 để chuẩn bị cho lần gán tiếp theo
        }
    }
    s1[k] = '\0'; // kết thúc chuỗi
}

int main()
{
    char s1[] = "hello world";
    char s2[] = "ole";
    squeeze(s1, s2);
    printf("%s\n", s1); // kết quả: "h wrd"
    return 0;
}
