#include <stdio.h>

typedef struct{
    int x;
    int y;
}cood;

int main(){
    cood pos[2];
    printf("X1 = "); scanf("%d", &pos[0].x);
    printf("Y1 = "); scanf("%d", &pos[0].y);
    printf("X2 = "); scanf("%d", &pos[1].x);
    printf("Y2 = "); scanf("%d", &pos[1].y);

    printf("Distance = %.2f\n", sqrt((pos[0].x - pos[1].x)*(pos[0].x - pos[1].x) +
           (pos[0].y - pos[1].y)*(pos[0].y - pos[1].y)));
    return 0;
}
