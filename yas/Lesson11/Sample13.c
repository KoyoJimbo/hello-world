#include<stdio.h>


typedef enum Week{SUN, MON, TUE, WED,THU, FRI, SAT} Week;


int main(void)
{
    Week w;
    w = SUN;


    switch(w){
        case SUN: printf("日曜日です。\n"); break;
        case MON: printf("月曜日です。\n"); break;
        case TUE: printf("火曜日です。\n"); break;
        case WED: printf("水曜日です。\n"); break;
        case THU: printf("水曜日です。\n"); break;
        case FRI: printf("木曜日です。\n"); break;
        case SAT: printf("土曜日です。\n"); break;
        default: printf("何曜日だかわかりません。\n"); break;
    }


    return 0;
}

