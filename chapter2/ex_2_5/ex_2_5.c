#include <stdio.h>
/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
(The standard library function strpbrk does the same job but returns a pointer to the 
location.)  
Bài tập 2-5. Viết hàm any(s1,s2), trả về vị trí đầu tiên trong chuỗi s1 
mà bất kỳ ký tự nào trong chuỗi s2 xuất hiện, hoặc -1 nếu s1 không chứa các ký tự từ s2.
*/

int any(char s1[], char s2[])
{
    for(int i =0; s1[i] != '\0'; i++)
    {
        for(int j =0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            {
                return i; // trả về vị trí của ký tự trong s1
            }
        }
    }
    return -1; // không tìm thấy ký tự nào từ s2 trong s1
}


int main() {
    char s1[] = "hello world";
    char s2[] = "aeiou";
    int pos = any(s1, s2);
    if (pos != -1)
        printf("Ky tu dau tien trung la '%c' tai vi tri %d\n", s1[pos], pos);
    else
        printf("Ko co ky tu trung.\n");
    return 0;
}