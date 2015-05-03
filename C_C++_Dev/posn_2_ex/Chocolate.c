#include "stdio.h"

/*
TASK: Chocolate
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/


int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int fcount,n,i,m,x;
    int cho[2];
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &x);
            if(i >= 2){
                cho[i%2] = max(cho[i%2]+x, cho[(i-1)%2]);
            }else if(i == 0){
                cho[i%2] = x;
            }else{
                cho[i%2] = max(x, cho[(i-1)%2]);
            }
        }
        /*for(i = 0; i < n; i++){
            printf("%d ", cho[i]);
        }*/
        printf("%d\n", cho[(n-1)%2]);
    }
}
