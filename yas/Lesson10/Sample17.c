#include<stdio.h>
void show0(void);
void show1(void);
void show2(void);

int main(void){
	void (*pM[3])(void);
	int num;

	pM[0] = show0;
	pM[1] = show1;
	pM[2] = show2;


	printf("どののりものを呼び出しますか？(0:車　1:レーシングカー　2:飛行機)\n");
	scanf("%d",&num);


	if(0<= num && num <= 2)
		(*pM[num])();

	
	return 0;
	}

void show0(void){
		printf("車です。\n");
	}
void show1(void){
		printf("レーシングカーです。\n");
	}
void show2(void){
		printf("飛行機です。\n");
	}
	


