#include<stdio.h>
#define square(x) (x * x)
int main(void){
	int num, ans;


	printf("整数を入力して下さい。\n");
	scanf("%d",&num);


	ans = square(num);


	printf("入力した値の二乗は%dです。\n",ans);


    return 0;
}

