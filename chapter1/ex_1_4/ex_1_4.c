#include <stdio.h>
/*
Write a program to print the corresponding Celsius to Fahrenheit table.
Công thức: F = (9/5) * C + 32
*/
int main() {
    float celsius, fahrenheit;
    float lower, upper, step;

    lower = 0;    // lower limit of temperature table
    upper = 100;  // upper limit
    step = 10;    // step size

    celsius = lower;
    while (celsius <= upper) {
        fahrenheit = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }
}
