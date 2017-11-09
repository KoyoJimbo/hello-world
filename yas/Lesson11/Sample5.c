#include<stdio.h>


typedef struct Car
{
    int num;
    double gas;
}Car;


int main(void)
{
    Car car1 = {1234, 25.5};
    Car car2 = {4567, 52.2};


    printf("car1の車のナンバーは%d：ガソリン量は%fです。\n", car1.num,
        car1.gas);
    printf("car2の車のナンバーは%d：ガソリン量は%fです。\n", car2.num,
        car2.gas);


    car2 = car1;


    printf("car1をcar2に代入しました。\n");


    printf("car2のナンバーは%d；ガソリン量は%fになりました。\n",
        car2.num, car2.gas);


    return 0;
}

