#include "stdio.h"
int r,c,k,i,j;
char s;
char t[10][10],t2[10][10];
void putSpace(int n){
    for(;n>0;n--) putchar(' ');
}
void print45(){
    int i,j;
    for(i = 0; i < r; i++){
        putSpace(r-i-1);
        for(j = i; j >= 0&&i-j<c; j--){
            putchar(t[j][i-j]);
            putchar(' ');
        }
        putchar('\n');
    }
    for(i = 1; i < c; i++){
        putSpace(i);
        for(j = r-1; j>=0&&i+r-1-j<c; j--){
            putchar(t[j][i+r-1-j]);
            putchar(' ');
        }
        putchar('\n');
    }
}
void printT(){
    int i,j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            putchar(t[i][j]);
        }
        putchar('\n');
    }
}
int main(){

    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        scanf(" %s", t[i]);
    }
    scanf("%d", &k);
    k /= 45;
    for(; k>1; k -= 2){
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                t2[j][r-i-1] = t[i][j];
            }
        }
        s = r;
        r = c;
        c = s;
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                t[i][j] = t2[i][j];
            }
        }
    }
    if(k){
        print45();
    }else{
        printT();
    }
}
