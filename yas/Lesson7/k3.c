#include<stdio.h>
int main(void){
	char test[100];
	int i,num;
	    printf("文字列を入力して下さい\n");
		scanf("%s",test);
		num = 0;
		for(i=0; test[i]!='\0';i++){
			num++;
		}
		printf("文字列の長さは%dです。\n",num);
    return 0;
}

