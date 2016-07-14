#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int r,c,i,j,x,y,mx,my,k,tx,ty;
    char m[120][120];
    scanf("%d%d", &r, &c);

    for(i = 0; i < r; i++){
        scanf(" %s", m[i]);
    }
    for(i = 0,x=y=-1; i < r && x==-1; i++){
        for(j = 0; j < c && x==-1; j++){
            if(m[i][j]=='x'){
                x = i; y = j;
            }
        }
    }
    printf("%d %d ", x+1, y+1);
    tx = x+1, ty = y+1;
    for(i = 0; i+x<r && i+y<c; i++){
        for(j = 0; j <= i; j++){
            if(m[x+j][y+i]=='.'||m[x+i][y+j]=='.'){
                x = 10000;
                i--;
                break;
            }
        }
        if(x!=10000){
            for(j = 0; j <= i; j++){
                m[x+j][y+i]='-';
                m[x+i][y+j]='-';
            }
        }
    }
    printf("%d\n",i);
    x=y=10000;
    mx=my=-1;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(m[i][j]=='x'){
                if(i<x) x = i;
                if(j<y) y = j;
                if(i>mx) mx = i;
                if(j>my) my = j;
            }
        }
    }
    if(mx==-1){
        printf("%d %d %d\n",tx,ty,1);
    }else{
        if(mx-x<my-y){
            for(k=0; x>=0&&mx-x<=my-y; x--){
                for(j = y; j<=my; j++){
                    if(m[x][j]=='.'){
                        k = 1;
                        break;
                    }
                }
                if(k) break;
            }
            x++;
        }else if(mx-x>my-y){
            for(k=0; y>=0&&mx-x>=my-y; y--){
                for(j = x; j<=mx; j++){
                    if(m[j][y]=='.'){
                        k = 1;
                        break;
                    }
                }
                if(k) break;
            }
            y++;
        }
        printf("%d %d %d\n", x+1,y+1,max(mx-x,my-y)+1);
    }
}
