#include "stdio.h"
#include "stdlib.h"

/*
TASK: Coupon
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM: Code::Blocks 12.11
*/

int book[8000];

int swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int quicksort(int a[], int size){
    int i = 1,j  = size-1, pivot, x;
    //swap(&a[size/2], &a[0]);
    pivot = a[0];
    if(size <= 1){
        return;
    }
    while(i <= j){
        if(a[i] >= pivot && a[j] < pivot){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
        if(a[i] < pivot){
            i++;
        }
        if(a[j] >= pivot){
            j--;
        }
    }

    swap(&a[0], &a[j]);
    quicksort(a+j+1, size-j-1);
    quicksort(a,j);
}

int main(){
    int n,m;
    int x,y,z,min,i,isBreak, k;
    int minX, minY, minZ,sum;
    FILE* in;
    FILE* out;
    char inname[15];
    char outname[15];

    for(k = 0; k < 10; k++){
        sprintf(inname,"input%d.txt", k);
        sprintf(outname,"output%d.txt", k);
        in = fopen(inname, "r");
        out = fopen(outname, "w+");
        fscanf(in,"%d%d", &n, &m);
        for(i = 0; i < n; i++){
            fscanf(in,"%d", &book[i]);
        }
        quicksort(book, n);
        min = 999999;

        minX = 0;
        minY = 0;
        minZ = 0;
        isBreak = 0;
        for(x = 0; x < n-2 && isBreak != 2; x++){
            for(y = x+1; y < n-1 && isBreak != 2; y++){
                isBreak = 0;
                for(z = y+1; z < n && !isBreak; z++){
                    sum = book[x]+book[y]+book[z];
                    if(sum > m){
                        isBreak = 1;
                    }else if(sum == m){
                        minX = book[x];
                        minY = book[y];
                        minZ = book[z];
                        isBreak = 2;
                    }else if(m-sum < min){
                        min = m-sum;
                        minX = book[x];
                        minY = book[y];
                        minZ = book[z];
                    }
                }
            }
        }
        fprintf(out,"%d\n%d\n%d\n", minX, minY, minZ);
    }
}
