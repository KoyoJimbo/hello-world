#include<stdio.h>


typedef struct Car{
    int num;
    double gas;
    struct Car *next;
}Car;


int main(void)
{
    Car car0;
    Car car1;
    Car car2;
    Car *pcar;


    car0.num = 1234; car0.gas = 25.5;
    car1.num = 4567; car1.gas = 52.2;
    car2.num = 7890; car2.gas = 20.5;


    car0.next = &car1;
    car1.next = &car2;
    car2.next = NULL;


    for(pcar = &car0; pcar!=NULL; pcar = pcar->next){
        printf("車のナンバーは%d：ガソリン量は%fです。\n", pcar->num,
            pcar->gas);
    }


    return 0;
}
