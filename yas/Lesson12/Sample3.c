#include<stdio.h>
int main(void){
    double num;
    printf("少数を入力して下さい。\n");
    scanf("%lf",&num);
    printf("少数以下３ケタで出力すると%.3fです。\n",num);

    return 0;
}

