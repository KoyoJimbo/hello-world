#include<stdio.h>


typedef union Year{
    int ad;
    int gengo;
}Year;


int main(void){
    Year myyear;
    int a, g;


    printf("西暦を入力して下さい。\n");
    scanf("%d",&a);


    myyear.ad = a;


    printf("西暦は%dです。\n", myyear.ad);
    printf("元号は%dです。\n", myyear.gengo);


    printf("元号を入力して下さい。\n");
    scanf("%d",&g);


    myyear.gengo = g;


    printf("元号は%dです。\n", myyear.gengo);
    printf("西暦は%dです。\n", myyear.ad);


    return 0;
}
