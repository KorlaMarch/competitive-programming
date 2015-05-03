#include "stdio.h"
int n,i,j,c;
char till[19][19];
int abs(int n){
    return n<0?n*-1:n;
}
int count(int x, int y, int ox, int oy,char ch){
    int co = 0;
    if(x<n&&y<n&&ch==till[x][y]){
        till[x][y] = 0;
        if(abs(ox-x)<=1&&abs(oy-y)<=1){
            co = 1;
        }else{
            co=-99999999;
        }
        return count(x+1,y,ox,oy,ch)+count(x,y+1,ox,oy,ch)+count(x-1,y,ox,oy,ch)+count(x,y-1,ox,oy,ch)+co;
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &till[i][j]);
        }
    }
    for(i = c = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(till[i][j]&&count(i,j,i,j,till[i][j])==3){
                c++;
            }
        }
    }
    printf("%d\n",c);
}
