#include "stdio.h"
int n,s,h,i,j,maxh=0,maxp=0;
char mt[10][90];
void makeF(int x, int y, int s){
    int i;
    for(i=0;i<s;i++){
        mt[x][y+i] = 'X';
    }
    if(mt[x][y+i]=='/'){
        mt[x][y+i] = 'v';
    }else if(mt[x][y+i]==0){
        mt[x][y+i] = '\\';
    }
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&s,&h);
        if(h>maxh) maxh=h;
        if(s+2*h>maxp) maxp = s+2*h;
        for(j = 0; j < h; j++){
            if(mt[j][s+j-1]=='\\'){
                mt[j][s+j-1] = 'v';
            }else if(mt[j][s+j-1]==0){
                mt[j][s+j-1] = '/';
            }
            makeF(j,s+j,(h-j-1)*2);
        }
    }
    for(i = maxh-1; i>=0; i--){
        for(j = 0; j < maxp-1; j++){
            if(mt[i][j]){
                putchar(mt[i][j]);
            }else{
                putchar('.');
            }
        }
        putchar('\n');
    }
}
