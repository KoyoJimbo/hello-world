#include<stdio.h>
int a = 0;
void func(void){
	int b = 0;
	static int c = 0;

	printf("変数aは%d変数bは%d変数cは%dです。\n",a,b,c);
	a++;
	b++;
	c++;
}
int main(void){
	int i;

	for(i=0;i<5;i++)
		func();
	
    return 0;
}

