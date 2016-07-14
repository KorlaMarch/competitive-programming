#include "stdio.h"
int n,m,i,j,x,y,k,o;
char wt[26][26];
char s[16];

int mw(int x, int y, int cx, int cy, int i){
    if(i<0||s[i]=='\0'){
        return 1;
    }else if(x>=n||y>=m||x<0||y<0||wt[x][y]!=s[i]){
        return 0;
    }else{
        return mw(x+cx, y+cy, cx, cy, i+1);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        getchar();
        for(j = 0; j < m; j++){
            wt[i][j] = getchar();
            if(wt[i][j] >= 'a' && wt[i][j] <= 'z'){
                wt[i][j] -= 0x20;
            }
        }
    }
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        scanf(" %s", s);
        for(j = 0; s[j]; j++){
            if(s[j]>='a' && s[j]<='z') s[j] -= 0x20;
        }
        for(x = o = 0; x < n && !o; x++){
            for(y = 0; y < m && !o; y++){
                if(mw(x,y,0,1,0)||
                   mw(x,y,1,0,0)||
                   mw(x,y,1,1,0)||
                   mw(x,y,1,-1,0)||
                   mw(x,y,0,-1,0)||
                   mw(x,y,-1,0,0)||
                   mw(x,y,-1,-1,0)||
                   mw(x,y,-1,1,0)){
                    printf("%d %d\n", x,y);
                    o = 1;
                   }
            }
        }
    }
}
