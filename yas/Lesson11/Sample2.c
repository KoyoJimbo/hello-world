#include<stdio.h>

struct Car{
	int num;
	double gas;
};

int main(void)
{
    struct Car car1;
    printf("ナンバーを入力して下さい。\n");
    scanf("%d",&car1.num);


    printf("ガソリン量を入力して下さい。\n");
    scanf("%lf",&car1.gas);


    printf("車のナンバーは%d：ガソリン量は%fです。\n",car1.num,car1.gas);


    return 0;
}

