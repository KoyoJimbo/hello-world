#include<stdio.h>
#include<ctype.h>
int A(char str[]);
int a(char str[]);
int main(void){
		char str[100];
		int i,j;
		printf("文字列を入力して下さい。(英字)\n");
		scanf("%s",str);

		for(i=0;str[i] != '\0';i++){
				str[i] = toupper(str[i]);
			}
		printf("大文字にすると%sです。\n",str);
		for(i=0;str[i] != '\0';i++){
				str[i] = tolower(str[i]);
			}
		printf("小文字にすると%sです。\n",str);

		return 0;
}


