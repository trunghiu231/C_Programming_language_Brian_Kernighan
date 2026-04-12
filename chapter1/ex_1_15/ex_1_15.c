#include <stdio.h>

/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2
for conversion.  Chuyển đổi nhiệt độ từ C sang F. C = 5/9(f-32)
 */

float fahrenheit_to_celsius(float fahrenheit);

int main()
{
    float fahrenheit, celsius;
    int lower, upper, step;
    lower = 0;   // nhiệt độ thấp nhất
    upper = 300; // nhiệt độ cao nhất
    step = 20;   // bước nhảy

    fahrenheit = lower;

    while(fahrenheit <= upper)
    {
        celsius = fahrenheit_to_celsius(fahrenheit);
        printf("%3.0f %6.1f\n", fahrenheit, celsius);
        fahrenheit += step;
    }

    return 0;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}
