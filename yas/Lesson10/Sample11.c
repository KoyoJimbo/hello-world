#include<stdio.h>
#include<string.h>
int main(void){
		int str_len;
		char str[100];
		printf("文字列（英数字）を入力してください。\n");
		scanf("%s",str);
		str_len = strlen(str);
		printf("文字列の長さは%dです。\n",str_len);
		return 0;
	}
