#include "stdio.h"
#include "stdlib.h"

/*
TASK: Bonus
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

struct homework{
    int dl;
    int bonus;
};

typedef struct homework hw;

int cmp(hw a, hw b){
    if(a.bonus == b.bonus){
        return a.dl < b.dl ? 1 : 0;
    }else if(a.bonus > b.bonus){
        return 1;
    }else{
        return 0;
    }
}

void swap(hw* a, hw *b){
    hw t = *a;
    *a = *b;
    *b = t;
}

void quicksort(hw a[], int size){
    int i = 1, j = size-1;
    hw pivot = a[0];

    if(size <= 1){
        return;
    }
    while(i <= j){
        //printf("quick %d %d %d %d\n", i,j, cmp(a[0], a[i]),cmp(a[j], a[0]) );
        if(!cmp(a[i],a[0]) && !cmp(a[0], a[j])){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }

        if(cmp(a[i],a[0])){
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
    int n,fcount,i,j;
    int sum;
    hw h[100];
    int d[100];
    FILE* in;
    FILE* out;
    char inname[15];
    char outname[15];

    for(fcount = 0; fcount < 5; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        in = fopen(inname, "r");
        out = fopen(outname, "w+");

        fscanf(in,"%d", &n);
        for(i = 0; i < n; i++){
            fscanf(in,"%d%d", &h[i].dl, &h[i].bonus);
        }
        quicksort(h, n);
        for(i = 0; i < n; i++){
            d[i] = 0;
            //printf("%d %d\n", h[i].bonus, h[i].dl);
        }
        //printf("\n");
        sum = 0;
        for(i = 0; i < n; i++){
            //printf("%d\n", h[i].dl);
            for(j = h[i].dl-1; j >= 0 && d[j];j--);
            if(j >= 0){
                d[j] = 1;
                //printf("%d\n", h[i].bonus);
                sum += h[i].bonus;
            }
        }
        fprintf(out,"%d\n", sum);
    }
}
