#include "stdio.h"

/*
TASK: Store
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

int cmp(int a, int b){
    return a <= b ? 1 : 0;
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int a[], int size){
    int i = 1, j = size-1, pivot = a[0];
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
    int fcount,n,inT[50001], outT[50001],i, j;
    int count,m;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d%d", &inT[i], &outT[i]);
        }
        i = 0;
        j = 0;
        count = 0;
        m = 0;

        while(i < n){
            if(outT[j] <= inT[i]){
                count--;
                j++;
            }
            if(inT[i] <= outT[j]){
                count++;
                i++;
            }

            if(count > m){
                m = count;
            }
        }
        printf("%d\n", m-1);
    }
}
