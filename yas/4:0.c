

//文字だけのターン性対戦ゲームを作る

 

/*ポケもんみたいなものを作りたい。

  ポケモンと違う点。（最終形態）

  １、能力を制限以内で自由に振り分けられる。

  ２、交代時攻撃可能。

  選択には交代攻撃or攻撃しかない。*/

 

/*課題：素早さが効力を発揮しない*/

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<ctype.h>

#define NUMBER 7

 

int ho=1;

int j;

//構造体一覧

 

struct potencial {

  char name[NUMBER];

  int atk;

  int hp;

  int spd;

};
 

 

// pln　ポケモンの設定に使う
#define pln 10

//システムの流れ

int main(void){

  //ポケモンの設定開始
  int m,ut[pln],lt[pln],st[pln];
  char namae[pln];
  printf("せっていするよ！。('ワ'＊)\n");
  for(m=1;m<=6;m++){
      printf("%d人目の名前を入力してね！:" ,m);
      scanf("%s",&namae[m]);
      while(1){
      printf("%sのこうげきりょく:",&namae[m]);
      scanf("%d",&ut[m]);
      printf("%sのHP:",&namae[m]);
      scanf("%d",&lt[m]);
      st[m]=100-ut[m]-lt[m];
      printf("%sのすばやさは%dになった！\n",&namae[m],st[m]);
      if(ut[m]>0 && lt[m]>0 && st[m]>0) {
        break;
      }
      else{
        printf("攻撃力とHPの合計が100より小さくなるようにしてね。d(-_^)\n ");   
      }
    }
  }
  //ポケモンの設定終わり
  //記憶開始
  int lt1[pln],v;
  for(v=0;v<=pln;v++){
    lt1[v]=lt[v];
  }

  //記憶終了
  

  struct potencial character[NUMBER]= {

    {"A",20,380,11},/*使わない*/

    {"B",ut[1],lt[1],100-ut[1]-lt[1]},

    {"C",ut[2],lt[2],100-ut[2]-lt[2]},

    {"D",ut[3],lt[3],100-ut[3]-lt[3]},

    {"E",ut[4],lt[4],100-ut[4]-lt[4]},

    {"F",ut[5],lt[5],100-ut[5]-lt[5]},

    {"G",ut[6],lt[6],100-ut[6]-lt[6]},

 

  };//キャラクターの能力値

 

  int i=1;

  int ho=1;

  int go=4;

  /*HPが０になるまでループ */

  while((character[4].hp>0 || character[5].hp>0 || character[6].hp>0) && (character[1].hp>0 ||character[2].hp>0 || character[3].hp>0)){

 

    printf("%dターン目\n",i);

    /*hoがプレイヤー1*/

    printf("プレイヤー１の番");

    while(1){

      int s,u;

      printf("どうする？\n");

      printf("1--たたかう\n");

      printf("2--ポケモンをこうかんする\n");

      scanf("%d",&s);

      if(s==1){

        if(character[ho].hp > 0){

          printf("このままこうげきするよ\n");

          break;

        }

        else{

          printf("%sは休憩中だよ! 他の子を選択してね！\n",character[ho].name);

        }

 

      }

      //交換のループ始め

      else  if(s==2){

        while (1) {

          printf("どのポケモンにする？\n");

          if(character[1].hp > 0) {  printf("1--B\n"); }

 

          if(character[2].hp > 0)  { printf("2--C\n"); }

 

          if(character[3].hp > 0)  { printf("3--D\n"); }

          scanf("%d",&u);

          if(u==3){

            /*戦える場合と戦えない場合*/

            if(character[3].hp > 0){

              printf("Dちゃんがこうげきするよ！\n");

              ho =3;

              break;

            }

 

            else{

              printf("Dちゃんはもう休憩中だよ！\n");

            }

          }

 

 

 

          else if(u==2) {

            /*戦える場合と戦えない場合*/

            if(character[2].hp > 0){

              printf("cがこうげきするよ。\n");

              ho=2;

              break;

            }

 

            else{

              printf("cちゃんはもう休憩中だよ！\n");

            }

 

          }

 

          else if(u==1){

            /*戦える場合と戦えない場合*/

            if(character[1].hp > 0){

              printf("Bがこうげきするよ\n");

              ho=1;

              break;

            }

 

            else{

              printf("Bはもう休憩中だよ！");

            }

          }

          else{

            printf("入力しなおしてね！\n");

          }

        }

        //交換のループおわり

      }

      else{

        printf("ちゃんと入力してよ。(; ω ;)\n");

      }

    }

    /*ここまでコピー*/

 

    printf("%dターン目\n",i);

    /*goがプレイヤー２*/

    printf("プレイヤー2の番");

    while(1){

      int p,q;

      printf("どうする？\n");

      printf("1--たたかう\n");

      printf("2--ポケモンをこうかんする\n");

      scanf("%d",&p);

      if(p==1){

        if(character[go].hp > 0){

          printf("このままこうげきするよ\n");

          break;

        }

        else{

          printf("%sは休憩中だよ! 他の子を選択してね！\n",character[go].name);

        }

 

      }

      //交換のループ始め

      else  if(p==2){

        while (1) {

          printf("どのポケモンにする？\n");

          if(character[4].hp > 0) {  printf("1--E\n"); }

 

          if(character[5].hp > 0)  { printf("2--F\n"); }

 

          if(character[6].hp > 0)  { printf("3--G\n"); }

          scanf("%d",&q);

          if(q==3){

            /*戦える場合と戦えない場合*/

            if(character[6].hp > 0){

              printf("Gちゃんがこうげきするよ！\n");

              go =6;

              break;

            }

 

            else{

              printf("Gちゃんはもう休憩中だよ！\n");

            }

          }

 

 

 

          else if(q==2) {

            /*戦える場合と戦えない場合*/

            if(character[5].hp > 0){

              printf("Fがこうげきするよ。\n");

              go=5;

              break;

            }

 

            else{

              printf("Fちゃんはもう休憩中だよ！\n");

            }

 

          }

 

          else if(q==1){

            /*戦える場合と戦えない場合*/

            if(character[4].hp > 0){

              printf("Eがこうげきするよ\n");

              go=4;

              break;

            }

 

            else{

              printf("Eはもう休憩中だよ！");

            }

          }

          else{

            printf("入力しなおしてね！\n");

          }

        }

        //交換のループおわり

      }

      else{

        printf("ちゃんと入力してよ。(; ω ;)\n");

      }

    }

 

 

    //1->ho

 

    //戦闘の中身

 

    //早いほうが先制攻撃

    if(character[go].spd > character[ho].spd){

      character[ho].hp  = character[ho].hp - character[go].atk;

      printf("%sは%dダメージを受けた。\n",character[ho].name,character[go].atk);

 

      if(character[ho].hp > 0){

        character[go].hp = character[go].hp - character[ho].atk;

 

        printf("%sは%dダメージ受けた\n",character[go].name,character[ho].atk);

      }

      else{

        printf("%sは疲れちゃった。\n",character[ho].name);

 

      }

 

      for(j=1;j<=6;j++){

        printf("%s:hp残り%d\n",character[j].name,character[j].hp);

      }

    }

 

    else if(character[go].spd < character[ho].spd){

      character[go].hp= character[go].hp - character[ho].atk;

      printf("%sは%dダメージ受けた\n",character[go].name,character[ho].atk);

      if(character[go].hp > 0){

        character[ho].hp=character[ho].hp - character[go].atk;

      }

      else{

        printf("%sはつかれちゃった\n",character[go].name);

      }

      for(j=1;j<=6;j++){

        printf("%s:hp残り%d\n",character[j].name,character[j].hp);

      }

    }

    else{

      int w;

      srand(time(NULL));
      w = rand() % 2;

      printf("%d\n",w);

      if(w==1){

        //プレイヤー１攻撃開始

        character[ho].hp  = character[ho].hp - character[go].atk;

        printf("%sは%dダメージを受けた。\n",character[ho].name,character[go].atk);

 

        if(character[ho].hp > 0){

          character[go].hp = character[go].hp - character[ho].atk;

 

          printf("%sは%dダメージ受けた\n",character[go].name,character[ho].atk);

        }

        else{

          printf("%sは疲れちゃった。\n",character[ho].name);

 

        }

 

        for(j=1;j<=6;j++){

          printf("%s:hp残り%d\n",character[j].name,character[j].hp);

        }

        //攻撃終わり

      }

      else{

        //プレイヤー２攻撃開始

        character[go].hp= character[go].hp - character[ho].atk;

        printf("%sは%dダメージ受けた\n",character[go].name,character[ho].atk);

        if(character[go].hp > 0){

          character[ho].hp=character[ho].hp - character[go].atk;

          printf("%sは%dダメージ受けた\n",character[ho].name,character[go].atk);

        }

        else{

          printf("%sはつかれちゃった\n",character[go].name);

        }

        for(j=1;j<=6;j++){

          printf("%s:hp残り%d\n",character[j].name,character[j].hp);

        }

        //攻撃終了


      }

 

    }
    //page change start
    int z,l;
    for(z=0;z<=1;z++){
      printf("(つワC)\n");
      for(l=0;l<=10;l++){
        printf("*\n");
      }
      printf("(つ'ワ'C)\n");
      for(l=0;l<=10;l++){
        printf("*\n");
      }
    }
    //page change end
    //show hp start
    for(z=1;z<=6;z++){
      printf("%sの初期HP:%d\n",&namae[z],lt1[z]);
    }
    //show hp end


    i++;

  }

 

 

 

 

  if(character[1].hp <= 0 && character[2].hp <= 0 && character[3].hp <=0){

    printf("プレイヤー２　winner!\n");

  }

  else{

    printf("プレイヤー１　winner!\n");

  }

 

 

  return 0;

}

 


 
