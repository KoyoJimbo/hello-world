#include<stdio.h>
#define MAX(x,y)(x > y ? x : y)

int main(void){
	int num1, num2, ans;


	printf("1番目の整数を入力して下さい。\n");
	scanf("%d",&num1);


	printf("2番目の整数を入力して下さい。\n");
	scanf("%d",&num2);


	ans = MAX(num1,num2);


Printf("最大値は%dです。",ans);


    return 0;
}

