#include<stdio.h>

typedef struct Car{
    int num;
    double gas;
}Car;

void show(Car c);

int main(void)
{
    Car car1 = {0, 0.0};


    printf("ナンバーを入力して下さい。\n");
    scanf("%d",&car1.num);
    printf("ガソリン量を入力して下さい。\n");
    scanf("%lf",&car1.gas);


    show(car1);


    return 0;
}


void show(Car c)
{
    printf("車のナンバーは%d：ガソリン量は%fです。\n",c.num,c.gas);
}
