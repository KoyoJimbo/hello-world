#include<stdio.h>
int main(void){
    int test[5];
	int i, j;


	printf("5人の点数を入力してください。\n");
	for(i=0;i<5;i++){
		scanf("%d",&test[i]);
	}

	for(j=0;j<5;j++){
		printf("%d番目の人の点数は%dです。\n",j+1,test[j]);
	}
return 0;
}



