#include <stdio.h> 
 
/*  Write a program to print the value of EOF.
EOF is typically defined as -1.  */

int main() {

    printf("%d\n", EOF);
    int c;
    c = getchar() != EOF;
    printf("%d\n", EOF);

}