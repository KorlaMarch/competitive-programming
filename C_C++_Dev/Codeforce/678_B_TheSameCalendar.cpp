#include "stdio.h"

int y,sp,i;
bool isBL;
bool isLY(int n){
    if(n%400==0) return true;
    if(n%100==0) return false;
    if(n%4==0) return true;
    return false;
}

int main(){
    scanf("%d",&y);
    isBL = isLY(y);
    for(sp = 0; sp==0||sp%7||isBL!=isLY(y); y++){
        if(isLY(y)) sp += 2;
        else sp++;
    }
    printf("%d\n",y);
}
