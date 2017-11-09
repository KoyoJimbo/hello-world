#include<stdio.h>
#include<string.h>
int main(void){
	char str[100];
	int str_len;
		printf("文字列を入力して下さい。\n");
		scanf("%s",str);
		str_len = strlen(str);
		printf("文字列の長さは%dです。\n",str_len);
	return 0;
	}
