#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct{
    int x;
    int y;
}pos;

typedef struct{
    pos a,b;
}rect;

int inRect(rect r, pos p){
    return p.x > r.a.x && p.x < r.b.x
    && p.y > r.a.y && p.y < r.b.y;
}

int main(){
    pos a[100];
    rect r;
    int i,j,c;
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        a[i].x = rand()%200;
        a[i].y = rand()%200;
    }
    scanf("%d%d%d%d", &r.a.x, &r.a.y, &r.b.x, &r.b.y);
    for(i = 0,c = 0; i < 100; i++){
        if(inRect(r,a[i])){
            c++;
            printf("Pos:%d %d\n", a[i].x, a[i].y);
        }
    }
    printf("Total %d position(s).\n", c);
}
