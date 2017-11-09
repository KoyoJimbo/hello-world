#include <stdio.h>
#include <malloc.h>

#define SIZE 50
void init(void);
void add(void);
void delete(void);
void display(void);

void enqueue(int n);
int dequeue(void);
int isFull(void);
int isEmpty(void);

int queue[SIZE];
int head, tail;


int main(void)
{
  int res;


  init ();

  while(1){
    printf("1--追加\t2--削除\t3--表示\t0--終了\n");
    scanf("%d",&res);
    if(!res){
      break;
    }
    switch(res){
    case 1:
      add();
      break;
    case 2:
      delete();
      break;
    case 3:
      display();
      break;
    }
  }
  return 0;
}

void init(void)
{
  head = 0;
  tail = 0;
}
void display(void)
{
  int i;

  printf("---\n");
  for(i=head%SIZE;i<tail%SIZE;i++){
    printf("%d\n",queue[i]);
  }
  printf("---\n");
}
void add(void){
  int n;
  if(isFull())
    return;
  printf("整数を入力してください。\n");
  scanf("%d",&n);
  enqueue(n);
  printf("%dを追加しました。\n",n);
}
void delete(void)
{
  if(isEmpty())
    return;
  printf("%d取り出しました。\n",dequeue());
}
void enqueue(int n)
{
  queue[(tail++)%SIZE]=n;
}
int dequeue(void)
{
  return queue[(head++)%SIZE];
}
int isFull(void)
{
  if(head%SIZE == (tail+1)%SIZE){
    printf("キューが満杯です。\n");
    return 1;
  }
  return 0;
}
int isEmpty(void)
{
  if(head%SIZE == tail%SIZE){
    printf("キューは空です。\n");
    return 1;
  }
  return 0;
}
