#include<stdio.h>
int main(void){
	char test[100];
	int i,num;
	    printf("文字列を入力して下さい\n");
		scanf("%s",test);
		num = 0;
		for(i=0; test[i]!='\0';i++){
			if(test[i]=='a'){
				test[i] = 'b';
			}
		}
		printf("%sに置き換えました。\n",test);
    return 0;
}

