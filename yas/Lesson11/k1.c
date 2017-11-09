#include<stdio.h>


typedef struct Person{
    int age;
    double weight;
    double height;
}Person;




int main(void)
{
    Person p1;
    Person p2;


    printf("年齢を入力して下さい。\n");
    scanf("%d",&p1.age);
    printf("体重を入力して下さい。\n");
    scanf("%lf",&p1.weight);
    printf("身長を入力して下さい。\n");
    scanf("%lf",&p1.height);


    printf("年齢を入力して下さい。\n");
    scanf("%d",&p2.age);
    printf("体重を入力して下さい。\n");
    scanf("%lf",&p2.weight);
    printf("身長を入力して下さい。\n");
    scanf("%lf",&p2.height);


    printf("年齢%d体重%f身長%fです。\n",p1.age, p1.height, p1.weight);
    printf("年齢%d体重%f身長%fです。\n",p2.age, p2.height, p2.weight);


   return 0;
}
