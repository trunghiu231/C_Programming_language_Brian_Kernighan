#include <stdio.h>
/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.

Bài tập 3-3. Viết một hàm expand(s1,s2) mở rộng các ký hiệu viết tắt như a-z trong chuỗi s1
thành danh sách đầy đủ tương đương abc...xyz trong chuỗi s2. Cho phép chữ cái viết hoa hoặc
viết thường, chữ số, và chuẩn bị xử lý các trường hợp như a-b-c, a-z, 0-9 và -a-z.
Sắp xếp sao cho dấu gạch ngang (-) ở đầu hoặc cuối được hiểu theo nghĩa đen.
*/
/* expand: expand shorthand notations in s1 into s2 */
void expand(char s1[], char s2[])
{
    int i = 0, j = 0;
    char c;

    while (s1[i] != '\0')
    {
        /* Trường hợp là dấu '-' ở giữa và tạo thành range hợp lệ */
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0' && 
            ((s1[i-1] >= '0' && s1[i-1] <= '9' && s1[i+1] >= '0' && s1[i+1] <= '9') ||
             (s1[i-1] >= 'a' && s1[i-1] <= 'z' && s1[i+1] >= 'a' && s1[i+1] <= 'z') ||
             (s1[i-1] >= 'A' && s1[i-1] <= 'Z' && s1[i+1] >= 'A' && s1[i+1] <= 'Z')))
        {
            /* Mở rộng range: từ s1[i-1] đến s1[i+1] */
            for (c = s1[i-1] + 1; c <= s1[i+1]; ++c)
                s2[j++] = c;

            i += 2;        /* bỏ qua ký tự sau dấu '-' */
        }
        else
        {
            /* Các trường hợp khác: copy ký tự bình thường */
            s2[j++] = s1[i++];
        }
    }

    s2[j] = '\0';   /* kết thúc chuỗi */
}

/* Hàm test */
int main(void)
{
    char s1[100];
    char s2[1000];   /* s2 phải đủ lớn */

    // Các test case
    const char *tests[] = {
        "a-z",
        "A-Z",
        "0-9",
        "a-b-c",
        "a-z0-9",
        "-a-z",
        "a-z-",
        "A-B-C",
        "-0-9-",
        "x-y-z",
        NULL
    };

    for (int k = 0; tests[k] != NULL; ++k) {
        expand((char*)tests[k], s2);
        printf("%s  -->  %s\n", tests[k], s2);
    }

    return 0;
}