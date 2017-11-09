#include<stdio.h>

int length(char str[]);

int main(void){
	char str[100];
	int ans;


	printf("文字列を入力して下さい。\n");
	scanf("%s",str);


	ans = length(str);


	printf("文字列の長さは%dです。\n",ans);


	return 0;
	}


int length(char str[]){
		int i, c;


		c = 0;

		for(i=0; str[i] !='\0'; i++){
				c++;
			}
			return c;
	}
