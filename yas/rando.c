/*
 * C言語のサンプルプログラム - Webkaru
 * - 1 〜 10 の数をランダムに出力 - 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void){
 
  int s;
 
  /* 乱数の種を初期化 */
  srand(time(NULL));
  
  /* 1 〜 10 のランダムな数 */
  s = rand() % 2 ;
 
  /* 出力 */
  printf("%d\n", s);
 
  return 0;
}


        
