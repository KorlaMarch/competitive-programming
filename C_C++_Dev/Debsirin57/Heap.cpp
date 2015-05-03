#include "stdio.h"
#include "stdlib.h"

#define MAX_HEAP 100

struct heap{
    int node[MAX_HEAP];
    int end;
};

typedef struct heap* heapPTR;

int swapTime;
int compareTime;

void swap(int *a, int *b){
    swapTime++;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

heapPTR newheap(){
    heapPTR h = (heapPTR)malloc(sizeof(struct heap));
    h->end = 0;
    return h;
}

void reheapup(heapPTR h, int pos){
    compareTime++;
    if(pos == 0 || h->node[pos] < h->node[(pos-1)/2]){
        return;
    }else{
        swap(&(h->node[pos]), &(h->node[(pos-1)/2]));
        reheapup(h, (pos-1)/2);
    }
}

void reheapdown(heapPTR h, int pos){
    if(pos*2+2 >= h->end){
        compareTime++;
        return;
    }if(h->node[pos*2+1] > h->node[pos] || h->node[pos*2+2] > h->node[pos]){
        compareTime += 2;
        if(h->node[pos*2+1] >= h->node[pos*2+2]){
            swap(&(h->node[pos]), &(h->node[pos*2+1]));
            reheapdown(h, pos*2+1);
        }else{
            swap(&(h->node[pos]), &(h->node[pos*2+2]));
            reheapdown(h, pos*2+2);
        }
    }else{
        compareTime++;
        return;
    }
}

void addNode(heapPTR h, int data){
    h->node[h->end] = data;
    reheapup(h, h->end);
    h->end++;
}

void heapsort(heapPTR h, int num[], int l){
    int len, n;
    swapTime = 0;
    compareTime = 0;
    //make tree
    for(n = 0; n < l; n++){
        addNode(h, num[n]);
    }

    //sorting
    for(len = h->end; h->end > 1; ){
        swap(&(h->node[0]), &(h->node[h->end-1]));
        h->end--;
        reheapdown(h, 0);
    }

    //output
    printf("Heap sort complete!\n");
    for(n = 0; n < len; n++){
        printf("%d ", h->node[n]);
    }
    printf("\nTotal Swap: %d\n", swapTime);
    printf("Total Compare: %d\n", compareTime);
}

int main(){
    heapPTR h = newheap();
    int data[] = {4,5,3,1,25,9,12,7,6,1};
    heapsort(h, data, 10);
}
