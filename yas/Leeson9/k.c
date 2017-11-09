#include<stdio.h>
void swap(int *x, int *y,int *z); 
int main(void)
{
	int t1,t2,a;
		printf("２科目分の点数を入力してください。\n"); 
		scanf("%d",&t1);
		scanf("%d",&t2);

		printf("加算する点数を入力して下さい。\n"); 
		scanf("%d",&a);
		swap(&t1,&t2,&a);
		printf("%d点加算しましたので\n",a); 
		printf("科目１は%d点となりました。",t1); 
		printf("科目２は%d点となりました。",t2); 

	}


	void swap(int *x, int *y,int *z){
		*x += *z;
		*y += *z;

		} 
