#include<stdio.h>


int power(int x, int y){
	int i;
	int b = x;

	for(i=1;i<y;i++){x =  x*b;}

	return x;
}


int main(void){
	int num1,num2,ans;

	printf("1番目の整数を入力して下さい。\n");
	scanf("%d",&num1);

	printf("2番目の整数を入力して下さい。\n");
	scanf("%d",&num2);

	ans = power(num1, num2);

	printf("%dの%d乗は%dです。\n",num1, num2, ans);

    return 0;
}

