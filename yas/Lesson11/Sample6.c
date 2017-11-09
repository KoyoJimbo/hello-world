#include<stdio.h>


typedef struct Car
{
    int num;
    double gas;
}Car;


int main(void)
{
    printf("int型なサイズは%ldバイトです。\n", sizeof(int));
    printf("double型サイズは%ldバイトです。\n", sizeof(double));
    printf("構造体struct Car型のサイズは%ldバイトです。\n",sizeof(Car));
    printf("構造体struct Car型へのポインタはサイズは%ldバイトです。\n",
        sizeof(Car *));


    return 0;
}

