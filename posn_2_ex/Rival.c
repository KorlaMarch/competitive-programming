#include "stdio.h"

/*
TASK: Rival
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int min;
int ys[10000];
int os[10000];

int diff(int a, int b){
    int n = a-b;
    if(n < 0){
        return n*-1;
    }else{
        return n;
    }
}

void FindMin(int sum,int pos, int n, int n2, int m){
    int i,lim;
    if(sum > min){
        return;
    }
    if(n == m){
        if(sum < min){
            min = sum;
        }
        return;
    }

    lim = n2-m+n;
    for(i = pos; i < lim; i++){
        FindMin(sum+diff(ys[i], os[n]), i+1, n+1, n2, m);
    }
}

int main(){
    int fcount,m,n,minDiff;
    int i,j;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 10; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++){
            scanf("%d", &ys[i]);
        }

        for(i = 0; i < m; i++){
            scanf("%d", &os[i]);
        }
        min = 9999;
        FindMin(0,0,0,n,m);
        printf("%d\n", min);
    }
    return 0;
}
