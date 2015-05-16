#include "stdio.h"
int m,n,t,i,j,p;
char canR[101][45];
char st[101];
char c;

int main(){
    scanf("%d%d%d ",&m,&n,&t);
    canR[0][n-1] = 1;
    for(i = 1; i <= t; i++){
        for(j = 0; j < m; j++){
            while((c = getchar())==' ');
            getchar();
            if(c=='0'&&(canR[i-1][j]||(j?canR[i-1][j-1]:0)||(j+1<m?canR[i-1][j+1]:0))){
                canR[i][j] = 1;
            }
        }
    }
    for(i = 0; i < m; i++){
        if(canR[t][i]==1){
            n = i;
            break;
        }
    }
    for(p=0,i=t-1;i>=0;i--){
        if(canR[i][n]){
            st[p++] = '3';
        }else if(n+1<m&&canR[i][n+1]){
            st[p++] = '1';
            n++;
        }else if(n&&canR[i][n-1]){
            st[p++] = '2';
            n--;
        }
    }
    while(p-->0){
        putchar(st[p]);
        putchar('\n');
    }
}
