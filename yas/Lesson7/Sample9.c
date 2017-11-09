#include<stdio.h>
int main(void){
    char str[] = "Hello";
	int i;
	
	printf("Hello\n");
	
	for(i=0;str[i] != '\0';i++){
		printf("%c*",str[i]);
	}
	printf("\n");

return 0;
}

