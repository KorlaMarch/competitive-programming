#include <stdio.h>

int main(){
    float oldC = 0, newC = 0;
    int dis, radio, air;
    scanf("%d", &dis);
    scanf("%d%d", &radio, &air);

    oldC += 35;
    newC += 50;

    if(radio == 1){
        oldC += 20;
        newC += 50;
    }

    if(air == 1){
        oldC += 50;
        newC += 100;
    }

    if(dis > 20){
        oldC += 5.5 * (dis - 20);
        newC += 12 * (dis - 20);
        dis = 20;
    }

    if(dis > 12){
        oldC += 5 * (dis - 12);
        newC += 12 * (dis - 12);
        dis = 12;
    }

    if(dis > 2){
        oldC += 4.5 * (dis - 2);
        newC += 12 * (dis - 2);
        dis = 2;
    }

    if(dis > 1){
        oldC += 4.5;
        dis = 1;
    }

    printf("%.1f\n%.1f\n%.1f\n", oldC, newC, newC - oldC);
    return 0;
}
