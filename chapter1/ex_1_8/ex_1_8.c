#include<stdio.h>

int main(){
    int c;
    int blanks = 0, tabs = 0, newlines = 0;

    while((c = getchar()) != EOF){
        if(c == ' '){
            ++blanks;
        }
        else if(c == '\t'){
            ++tabs;
        }
        else if (c== '\n'){
            ++newlines;
        }
    }
    printf("\nBlanks: %d\n", blanks); //Khoảng trống
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

}