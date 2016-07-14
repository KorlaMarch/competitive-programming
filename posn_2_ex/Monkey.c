#include "stdio.h"

/*
TASK: Monkey
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

struct mon{
    int pos;
    int m;
};

typedef struct mon Monkey;

int cmp(Monkey a, Monkey b){
    return a.pos < b.pos ? 1 : 0;
}

void swap(Monkey *a, Monkey *b){
    Monkey t = *a;
    *a = *b;
    *b = t;
}

void quicksort(Monkey a[], int size){
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
    quicksort(a, j);
    quicksort(a+j+1, size-j-1);
}

int main(){
    int fcount,m,n,i,x,y;
    int b[20001];
    Monkey mo[1001];
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++){
            b[i] = i+1;
        }
        for(i = 0; i < m; i++){
            scanf("%d%d", &mo[i].pos, &mo[i].m);
        }
        quicksort(mo, m);

        for(i = 0; i < m; i++){
            x = b[mo[i].m];
            b[mo[i].m] = b[mo[i].m-1];
            b[mo[i].m-1] = x;
        }
        for(i = 0; i < n; i++){
            if(i+1 != n){
                printf("%d ", b[i]);
            }else{
                printf("%d", b[i]);
            }

        }
        printf("\n");
    }
}
