#include<stdio.h>
int a = 0;
void func(void){
	int c = 2;


	printf("func関数では変数aとcは使えます。\n");
	printf("変数aの値は%dです。\n",a);

	printf("変数cの値は%dです。\n",c);
}
int main(void){
	int b = 1;

	printf("main関数では変数aとbが使えます。\n");
	printf("変数aの値は%dです。\n",a);
	printf("変数bの値は%dです。\n",b);
	func();


    return 0;
}

