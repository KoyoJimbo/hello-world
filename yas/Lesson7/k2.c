#include<stdio.h>
#define NUM 5
int main(void){
	int test[NUM];
	int max;
	int i,j;

	max = 0;
	printf("テストの点数を入力して下さい。\n");
	for(i=0; i<NUM; i++){
		scanf("%d",&test[i]);
		if(test[i]>=70)
			max++;
	}
	for(j=0;j<NUM;j++){
		printf("%d番目の人の点数は%dです。\n",j+1,test[j]);
	}
	printf("70点以上の学生は%d人です。\n",max);

return 0;
}
