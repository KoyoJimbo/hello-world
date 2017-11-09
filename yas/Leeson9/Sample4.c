#include<stdio.h>
int main(void)
{
		int a,b;
		int *pA;

		a = 5;
		b = 10;

		pA = &a;

		printf("変数aの値は%dです。\n",a); 
		printf("ポインタpAの値は%pの変更されました。\n",pA); 
		printf("*pAの値は%dです。\n",*pA); 
		return 0;

	}

