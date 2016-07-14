#include "stdio.h"
int n,m,i,j,a,maxA;
char flower[30][31];

int getA(int i, int j){
    int a = 1;
    flower[i][j] = '=';
    if(i&&flower[i-1][j]=='.') a += getA(i-1,j);
    if(j&&flower[i][j-1]=='.') a += getA(i,j-1);
    if(i+1<n&&flower[i+1][j]=='.') a += getA(i+1,j);
    if(j+1<m&&flower[i][j+1]=='.') a += getA(i,j+1);
    return a;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++) scanf(" %30s", flower[i]);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(flower[i][j]=='#'){
                if(i&&flower[i-1][j]!='#') flower[i-1][j] = '-';
                if(j&&flower[i][j-1]!='#') flower[i][j-1] = '-';
                if(i+1<n&&flower[i+1][j]!='#') flower[i+1][j] = '-';
                if(j+1<m&&flower[i][j+1]!='#') flower[i][j+1] = '-';
            }
        }
    }
    for(i=maxA=0; i < n; i++){
        for(j = 0; j < m; j++){
            if(flower[i][j]=='.'){
                a = getA(i,j);
                if(a>maxA) maxA = a;
            }
        }
    }
    printf("%d\n",maxA);
}
