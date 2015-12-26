#include "stdio.h"

int n,m,i,x,y,c;
char isV[501][501];
char s[100005];
int main(){
    scanf("%d%d%d%d %s",&n,&m,&x,&y,s);
    for(i = 0; s[i]; i++){
        if(!isV[x][y]){
            isV[x][y] = 1;
            c++;
            printf("1 ");
        }else printf("0 ");
        if(s[i]=='U'&&x>1) x--;
        else if(s[i]=='D'&&x<n) x++;
        else if(s[i]=='L'&&y>1) y--;
        else if(s[i]=='R'&&y<m) y++;
    }
    printf("%d\n",n*m-c);
}
