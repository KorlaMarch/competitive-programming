#include "stdio.h"

/*
TASK: Train
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

struct train{
    int s;
    int d;
};

typedef struct train tra;

int cmp(tra a, tra b){
    if(a.s == b.s){
        return a.d > b.d ? 1 : 0;
    }else{
        return a.s < b.s ? 1 : 0;
    }
}

void swap(tra* a, tra* b){
    tra t = *a;
    *a = *b;
    *b = t;
}

void quicksort(tra a[], int size){
    int i = 1, j = size-1;
    if(size <= 1){
        return;
    }
    while(i <= j){
        if(!cmp(a[i], a[0]) && !cmp(a[0], a[j])){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
        if(cmp(a[i], a[0])){
            i++;
        }
        if(cmp(a[0], a[j])){
            j--;
        }
    }
    swap(&a[0], &a[j]);
    quicksort(a,j);
    quicksort(a+j+1,size-j-1);
}

int main(){
    int m,n;
    int i,j;
    int maxT;
    int fcount;
    tra table[1000];
    int tarnCount[1000];
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 10; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);
        scanf("%d%d",&n, &m);
        for(i = 0; i < m; i++){
            scanf("%d%d", &table[i].s, &table[i].d);
        }
        quicksort(table, m);

        tarnCount[0] = 1;
        for(i = 1; i < m; i++){
            maxT = 0;
            for(j = i-1; j >= 0; j--){
                if(tarnCount[j] > maxT && table[j].d >= table[i].s && table[j].s != table[i].s){
                    maxT = tarnCount[j];
                }
            }
            //printf("count = %d %d %d\n",m,i, maxT+1);
            tarnCount[i] = maxT+1;
        }
        maxT = 0;
        for(i = 0; i < m; i++){
            if(tarnCount[i] > maxT){
                maxT = tarnCount[i];
            }
        }
        printf("%d\n", maxT);
    }
}
