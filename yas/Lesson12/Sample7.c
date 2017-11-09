#include<stdio.h>

int main(void){
    int ch;
    printf("文字列を続けて入力して下さい。\n");
    while((ch=getchar()) != EOF){
        putchar(ch);
    }
    return 0;
}
