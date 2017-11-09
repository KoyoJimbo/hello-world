#include<stdio.h>
#include<string.h>
int main(void){
		char str1[100];
		char str2[100];


		printf("1番目の文字列を入力して下さい。\n");
		scanf("%s",str1);

		printf("2番目の文字列を入力して下さい。\n");
		scanf("%s",str2);

		if(strcmp(str1,str2) == 0){
				printf("2つの文字列は同じです。\n");
			}
		else{
				printf("2つの文字列は異なります。\n");
			}
			return 0;
	}
