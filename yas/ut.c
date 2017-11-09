//文字だけのターン性対戦ゲームを作る

 

/*ポケもんみたいなものを作りたい。

  ポケモンと違う点。（最終形態）

  １、能力を制限以内で自由に振り分けられる。

  ２、交代時攻撃可能。

  選択には交代攻撃or攻撃しかない。*/

#include<stdio.h>

#define NUMBER 2

 

//構造体一覧

 

struct potencial {

  char name[NUMBER];

  int atk;

  int hp;

  int spd;

};

 

 

 

//システムの流れ

int main(void){

  struct potencial character[NUMBER]= {

    {"A",20,50,10},

    {"B",19,30,21},
    {"C",17,60,17},   

  };//キャラクターの能力値

 

 

  int i=1;

  //戦闘の中身

  /*HPが０になるまでループ */ while(character[0].hp>0 && character[1].hp>0){

    printf("%dターン目",i);

    //早いほうが先制攻撃

    if(A.spd > B.spd){

      B.hp  = B.hp - A.atk;

      printf("Bは%dダメージを受けた。",A.atk);

 

      A.hp = A.hp - B.atk;

      printf("Aは%dダメージ受けた",B.atk);

    }

 

    if else{

      A.hp= A.hp - B.atk;

      printf("Aは%dダメージ受けた",B.atk);

 

      B.hp=B.hp - A.atk;

      printf("Bは%dダメージ受けた",A.atk);

    }

  }

 

  if (B.hp <= 0)

    printf("Bの負け");

 

  if else

    printf("Aの負け");

 

  return 0;

}

 

 
