#include "stdio.h"

int t,k,i,j;
char s[4][5];
int xc,oc,dc;

bool check(){
    if(xc==4){
        printf("Case #%d: X won\n",k);
        return true;
    }else if(oc==4){
        printf("Case #%d: O won\n",k);
        return true;
    }
    return false;
}

void countXO(int x, int y, int dx, int dy){
    if(x<0||y<0||x>=4||y>=4) return;
    //printf("GET %d %d %c\n",x,y,s[x][y]);
    if(s[x][y]=='X') xc++;
    else if(s[x][y]=='O') oc++;
    else if(s[x][y]=='T'){
        xc++,oc++;
    }else dc++;
    countXO(x+dx,y+dy,dx,dy);
}

bool checkDI(){
    xc = oc = 0;
    countXO(0,0,1,1);
    if(check()) return true;

    xc = oc = 0;
    countXO(0,3,1,-1);
    if(check()) return true;
    return false;
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        for(i = 0; i < 4; i++){
            scanf(" %s",s[i]);
        }
        for(i=dc=0; i < 4; i++){
            xc = oc = 0;
            countXO(0,i,1,0);
            if(check()) break;

            xc = oc = 0;
            countXO(i,0,0,1);
            if(check()) break;
        }
        if(i==4&&!checkDI()){
            if(dc) printf("Case #%d: Game has not completed\n",k);
            else printf("Case #%d: Draw\n",k);
        }
    }
}
