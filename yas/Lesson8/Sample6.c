#include<stdio.h>
int buy(int x, int y){
	int z;


	printf("%d万円と%d万円の車を買いました。\n",x,y);
	z = x+y;
	return z;
}

int main(void){
	int num1,num2,sum;
	printf("いくらの車を買いますか?\n");
	scanf("%d",&num1);

	printf("いくらの車を買いますか?\n");
	scanf("%d",&num2);

	sum = buy(num1,num2);
	printf("合計で%d万円です。\n",sum);

    return 0;
}

