#include <stdio.h>
// /* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
// int binsearch(int x, int v[], int n)
// {
//     int low, high, mid;
//     low = 0;
//     high = n - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (x < v[mid])
//             high = mid + 1;
//         else if (x > v[mid])
//             low = mid + 1;
//         else /* found match */
//             return mid;
//     }
//     return -1; /* no match */
// }
/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.

Bài tập 3-1. Thuật toán tìm kiếm nhị phân của chúng ta thực hiện hai phép thử bên trong vòng lặp,
trong khi chỉ cần một phép thử là đủ (với cái giá là phải thực hiện nhiều phép thử hơn bên ngoài).
Hãy viết một phiên bản chỉ có một phép thử bên trong vòng lặp và đo sự khác biệt về thời gian chạy.

*/

int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low < high)
    {
        mid = low + (high - low) / 2; // tránh tràn số

        if (x <= v[mid])
            high = mid; // chỉ một phép so sánh
        else
            low = mid + 1;
    }

    // kiểm tra phần tử cuối cùng sau vòng lặp
    if (low < n && v[low] == x)
    {
        return low;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;

    printf("Position of 7:  %d\n", binsearch(7, v, n));  // 3
    printf("Position of 11: %d\n", binsearch(11, v, n)); // 5
    printf("Position of 4:  %d\n", binsearch(4, v, n));  // -1
    printf("Position of 19: %d\n", binsearch(19, v, n)); // 9
    printf("Position of 1:  %d\n", binsearch(1, v, n));  // 0

    return 0;
}