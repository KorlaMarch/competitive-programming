#include "stdio.h"
int dr[9],st[7];
int sp=0;
int find_s(int n, int c, int s){
    int i;
    if(s == 100 && c==7){
        return 1;
    }else if(n<0||s>100||c>7){
        return 0;
    }
    for(i = n; i>=0; i--){
        if(find_s(i-1,c+1,s+dr[i])){
            printf("%d\n", dr[i]);
            return 1;
        }
    }
    return 0;
}

int main(){
    int i;
    for(i = 0; i < 9; i++){
        scanf("%d", &dr[i]);
    }
    find_s(8,0,0);
}
