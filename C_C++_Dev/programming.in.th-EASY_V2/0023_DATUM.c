#include "stdio.h"

int toD(int d, int m){
    switch(m-1){
    case 11:
        d += 30;
    case 10:
        d += 31;
    case 9:
        d += 30;
    case 8:
        d += 31;
    case 7:
        d += 31;
    case 6:
        d += 30;
    case 5:
        d += 31;
    case 4:
        d += 30;
    case 3:
        d += 31;
    case 2:
        d += 28;
    case 1:
        d += 31;
    }
    return d;
}

int main(){
    int m,d;
    scanf("%d%d",&d,&m);
    d = toD(d,m);
    switch(d%7){
    case 0:
        printf("Wednesday\n");
        break;
    case 1:
        printf("Thursday\n");
        break;
    case 2:
        printf("Friday\n");
        break;
    case 3:
        printf("Saturday\n");
        break;
    case 4:
        printf("Sunday\n");
        break;
    case 5:
        printf("Monday\n");
        break;
    case 6:
        printf("Tuesday\n");
        break;
    }
}
