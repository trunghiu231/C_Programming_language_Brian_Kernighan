#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
Viết chương trình xác định phạm vi của các biến char, short, int và long,
cả có dấu và không dấu, bằng cách in các giá trị thích hợp từ các tiêu đề tiêu chuẩn
và bằng cách tính toán trực tiếp. Khó hơn nếu bạn tính toán chúng: xác định phạm vi của các loại dấu phẩy động khác nhau.

*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("In tu thu vien\n\n");
    printf("Integer types\n");
    printf("char           : %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char  : 0 to %u\n", UCHAR_MAX);
    printf("short          : %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short : 0 to %u\n", USHRT_MAX);
    printf("int            : %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int   : 0 to %u\n", UINT_MAX);
    printf("long           : %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long  : 0 to %lu\n", ULONG_MAX);

    printf("\nFloating-point types\n");
    printf("float          : %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double         : %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double    : %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    /*
       TÍNH TRỰC TIẾP (không dùng thư viện)
       Nguyên lý:
         - unsigned: dịch bit 1 sang trái đến khi tràn về 0, rồi -1
         - signed:   unsigned_max >> 1 = MAX, MIN = -MAX - 1*/
    printf("\nTINH TRUC TIEP\n\n");

    /* --- char --- */
    unsigned char uc = 0;
    --uc; /* tràn về 255 = UCHAR_MAX */
    signed char sc_max = uc >> 1;
    signed char sc_min = -sc_max - 1;
    printf("char           : %d to %d\n", sc_min, sc_max);
    printf("unsigned char  : 0 to %u\n", uc);

    /* --- short --- */
    unsigned short us = 0;
    --us;
    short ss_max = us >> 1;
    short ss_min = -ss_max - 1;
    printf("short          : %d to %d\n", ss_min, ss_max);
    printf("unsigned short : 0 to %u\n", us);

    /* --- int --- */
    unsigned int ui = 0;
    --ui;
    int si_max = ui >> 1;
    int si_min = -si_max - 1;
    printf("int            : %d to %d\n", si_min, si_max);
    printf("unsigned int   : 0 to %u\n", ui);

    /* --- long --- */
    unsigned long ul = 0;
    --ul;
    long sl_max = ul >> 1;
    long sl_min = -sl_max - 1;
    printf("long           : %ld to %ld\n", sl_min, sl_max);
    printf("unsigned long  : 0 to %lu\n", ul);

    /* --- float ---
       FLT_MANT_DIG - 1 bit mantissa, FLT_MAX_EXP số mũ tối đa
       max = (2 - 2^(1-FLT_MANT_DIG)) * 2^(FLT_MAX_EXP-1)
       Tính bằng cách dịch bit mantissa rồi nhân với base^exp */
    printf("\nFloating-point- Truc tiep\n");

    float f_max = 1.0F;
    int e;
    for (e = 0; e < FLT_MANT_DIG - 1; e++)
    {
        f_max = f_max * 2.0F + 1.0F; /* tích luỹ mantissa */
    }
    for (e = 0; e < FLT_MAX_EXP - FLT_MANT_DIG + 1; e++)
    {
        f_max *= 2.0F; /* nhân phần số mũ */
    }
    printf("float          : %e to %e\n", FLT_MIN, f_max);

    double d_max = 1.0;
    for (e = 0; e < DBL_MANT_DIG - 1; e++)
    {
        d_max = d_max * 2.0 + 1.0;
    }
    for (e = 0; e < DBL_MAX_EXP - DBL_MANT_DIG + 1; e++)
    {
        d_max *= 2.0;
    }
    printf("double         : %e to %e\n", DBL_MIN, d_max);

    long double ld_max = 1.0L;
    for (e = 0; e < LDBL_MANT_DIG - 1; e++)
    {
        ld_max = ld_max * 2.0L + 1.0L;
    }
    for (e = 0; e < LDBL_MAX_EXP - LDBL_MANT_DIG + 1; e++)
    {
        ld_max *= 2.0L;
    }
    printf("long double    : %Le to %Le\n", LDBL_MIN, ld_max);

    return 0;
}