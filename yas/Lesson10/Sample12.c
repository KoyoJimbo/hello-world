#include<stdio.h>
#include<string.h>
int main(void){
		char str1[10];
		char str2[10];

		strcpy(str1, "Hello");
		strcpy(str2,"Goodbye");

		printf("配列str1は%sです。\n",str1);
		printf("配列str2は%sです。\n",str2);

		return 0;
	}
