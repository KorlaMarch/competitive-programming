#include "stdio.h"

/*
TASK: Rival
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

struct n{
    int d;
    int p;
};

typedef struct n node;

int cmp(node a, node b){
    return a.d < b.d ? 1 : 0;
}

void swap(node *a, node *b){
    node t = *a;
    *a = *b;
    *b = t;
}

void fucksort(node a[], int size){
    int i, j, isSort = 1;
    for(i = 0; i < size && isSort; i++){
        isSort = 0;
        for(j = 1; j < size-i; j++){
            if(cmp(a[j], a[j-1])){
                swap(&a[j],&a[j-1]);
                isSort = 1;
            }
        }
    }
}

int main(){
    int n,k,i,s,j,fcount, x;
    node num[2001];
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);
        scanf("%d%d", &n, &k);
        for(i = 0; i < k; i++){
            scanf("%d", &s);
            for(j = 0; j < s; j++){
                scanf("%d", &num[j].d);
            }
            fucksort(num, s);
            num[0].p = num[0].d+1;
            if(s != 1){
                printf("%d ", num[0].p);
            }else{
                printf("%d", num[0].p);
            }

            for(j = 1; j < s; j++){
                num[j].p = num[j].d-num[j-1].d+num[j-1].p+1;
                if(j+1 == s){
                    printf("%d", num[j].p);
                }else{
                    printf("%d ", num[j].p);
                }

            }
            printf("\n");
        }
    }
}
