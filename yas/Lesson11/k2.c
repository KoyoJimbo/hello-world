#include<stdio.h>


typedef struct Person{
    int age;
    double weight;
    double height;
}Person;


void aging(Person *pc);


int main(void)
{
    Person p;


    printf("年齢を入力して下さい。\n");
    scanf("%d",&p.age);
    printf("体重を入力して下さい。\n");
    scanf("%lf",&p.weight);
    printf("身長を入力して下さい。\n");
    scanf("%lf",&p.height);


    printf("年齢%d体重%f身長%fです。\n",p.age, p.height, p.weight);

aging(&Person)
   return 0;
}


void aging(Person *p){
    pc-> p ++;
}
