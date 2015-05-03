#include "stdio.h"
#include "math.h"

/*
TASK: Column
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

#define SIZE 100

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
    int m,n,isMatch,i,x,k,j;
    int array[2][SIZE] = {};
    int fcount;
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);
        scanf("%d%d", &m, &n);
        for(i = 0; i < n; i++){
            array[0][i] = 0;
            array[1][i] = 0;
        }
        for(k = 0; k < 2; k++){
            for(i = 0; i < m; i++){
                for(j = 0; j < n; j++){
                    scanf("%d", &x);
                    array[k][j] += pow(x, i+3);
                }
            }
        }
        quicksort(array[0], n);
        quicksort(array[1], n);
        isMatch = 1;
        for(i = 0; i < n; i++){
            if(array[0][i] != array[1][i]){
                isMatch = 0;
                break;
            }
        }
        if(isMatch){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
