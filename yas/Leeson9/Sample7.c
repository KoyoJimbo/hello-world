#include<stdio.h>
int main(void)
{

void swap(int *x, int *y); 
		int num1 = 5;
		int num2 = 10;

		printf("変数num1の値は%dです。\n",num1); 
		printf("変数num2の値は%dです。\n",num2); 
		printf("変数num1とnum2の値を交換します。\n"); 

		swap(&num1,&num2); 

		printf("変数num1の値は%dです。\n",num1); 
		printf("変数num2の値は%dです。\n",num2);


		return 0;

	}


	//誤ったswap関数の定義
	void swap(int *x, int *y)
	{
			int tmp;

			tmp = *x;

			*x = *y;
			*y = tmp;
		}
