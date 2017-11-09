#include<stdio.h>
 
int srch_a(char str[]);

int main(void){
	char t[100];
	int ans;

	printf("文字列を入力してください。\n");
	scanf("%s",t);


	ans = srch_a(t);


	printf("%sの中にaは%d個あります。\n",t,ans);


	return 0;
}

int srch_a(char str[]){
	int i,c;
	c = 0;
	for(i=0; str[i]!='\0';i++ ){
		if(str[i]=='a'){
			c++;
		}
	}
	return c;
}
