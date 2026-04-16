#include <stdio.h>
#include <ctype.h>
#include <math.h>
/*
Exercise 4-2. Extend atof to handle scientific notation of the form
   123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.

Bài tập 4-2. Mở rộng hàm atof để xử lý ký hiệu khoa học có dạng
123.45e-6
trong đó một số dấu phẩy động có thể được theo sau bởi e hoặc E và một số mũ có dấu tùy chọn.

Công thức tính số thập phân có ký hiệu khoa học:
mEn = m * 10^n
Trong đó:
- m là phần thập phân (mantissa)
- n là số mũ (exponent) là số nguyên có thể có dấu âm hoặc dương
Ví dụ:
123.45e-6 có nghĩa là 123.45 * 10^(-6)
1.23E+10 có nghĩa là 1.23 * 10^(10)
1E-6 có nghĩa là 1*10^(-6)
*/

/* atof:  convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // Đọc dấu, nếu có thì dịch chỉ số i sang ký tự tiếp
        i++;
    for (val = 0.0; isdigit(s[i]); i++) // đọc phần nguyên và cộng dồn vào val
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) // Đọc phần thập phân
    {
        val = 10.0 * val + (s[i] - '0'); // Tiếp tục đọc phần thập phân như trước
        power *= 10;                     // Dùng cái này để chia cho đúng vị trí thập phân
    }
    val = sign * val / power; // val = 12345, power = 100 -> val/power = 123.45

    // Thêm code phần xử lý số mũ
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        int exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        int exp_val = 0;
        while (isdigit(s[i]))
        {
            exp_val = 10 * exp_val + (s[i] - '0');
            i++;
        }
        val *= pow(10, exp_sign * exp_val);
    }
}
int main()
{
    printf("%g\n", atof("123.45e-6")); // 0.00012345
    printf("%g\n", atof("1.2E3"));     // 1200
    printf("%g\n", atof("-4.56e+2"));  // -456
    return 0;
}