#include <stdio.h> 
 
/*  Verify that the expression getchar() != EOF is 0 or 1.
    EOF is typically defined as -1. 
    nếu đọc được khác EOF thì trả về 1, ngược lại trả về 0
    != có độ ưu tiên cao hơn = nên thực tế là != chạy trước rồi mới gán kết quả cho c
    */

int main() {

    int c;
    c = getchar() != EOF;
    printf("%d\n", c);
}