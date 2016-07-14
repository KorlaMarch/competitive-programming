#include "stdio.h"
int n,i,j;
char a[15][15],t[15][15];
char firstRow[15];
char c;

void click(int i, int j){
    t[i][j] = !t[i][j];
    if(i) t[i-1][j] = !t[i-1][j];
    if(j) t[i][j-1] = !t[i][j-1];
    if(i+1<n) t[i+1][j] = !t[i+1][j];
    if(j+1<n) t[i][j+1] = !t[i][j+1];
}

int solve(){
    int i,j,c;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            t[i][j] = a[i][j];
        }
    }
    for(i=c=0; i < n; i++){
        if(firstRow[i]){
            click(0,i);
            c++;
        }
    }
    for(i = 1; i < n; i++){
        for(j = 0; j < n; j++){
            if(t[i-1][j]){
                click(i,j);
                c++;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(t[n-1][i]) break;
    }
    if(i==n){
        //redo and print
        printf("%d\n",c);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                t[i][j] = a[i][j];
            }
        }
        for(i = 0; i < n; i++){
            if(firstRow[i]){
                click(0,i);
                printf("1 %d\n",i+1);
            }
        }
        for(i = 1; i < n; i++){
            for(j = 0; j < n; j++){
                if(t[i-1][j]){
                    click(i,j);
                    printf("%d %d\n",i+1,j+1);
                }
            }
        }
        return 1;
    }else{
        return 0;
    }
}

int findAns(int d){
    if(d>=n){
        if(solve()) return 1;
        else return 0;
    }else{
        firstRow[d] = 0;
        if(findAns(d+1)) return 1;
        firstRow[d] = 1;
        if(findAns(d+1)) return 1;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&c);
            a[i][j] ^= c;
        }
    }
    findAns(0);
}
