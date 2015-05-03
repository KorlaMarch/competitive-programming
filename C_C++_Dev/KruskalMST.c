#include "stdio.h"
#include "stdlib.h"

#define SIZE 500

struct edge{
    char so;
    char dis;
    int w;
};

typedef struct edge* edgeptr;

struct qu{
    edgeptr data[SIZE];
    int last;
};

typedef struct qu* queue;

int compare(edgeptr x, edgeptr y){
    return x->w < y->w ? 1 : 0;
}

void reheapup(queue q, int pos){
    edgeptr temp;
    if(pos <= 0){
        return;
    }
    if(compare(q->data[pos],q->data[(pos-1)/2])){
        temp = q->data[pos];
        q->data[pos] = q->data[(pos-1)/2];
        q->data[(pos-1)/2] = temp;
        reheapup(q, (pos-1)/2);
    }
}

int reheapdown(queue q, int pos){
    edgeptr temp;
    if(pos*2+1 >= q->last){
        return;
    }
    if(pos*2+2 == q->last || compare(q->data[pos*2+1], q->data[pos*2+2])){
        if(compare(q->data[pos*2+1], q->data[pos])){
            temp = q->data[pos];
            q->data[pos] = q->data[pos*2+1];
            q->data[pos*2+1] = temp;
            reheapdown(q, pos*2+1);
        }
    }else{
        if(compare(q->data[pos*2+2], q->data[pos])){
            temp = q->data[pos];
            q->data[pos] = q->data[pos*2+2];
            q->data[pos*2+2] = temp;
            reheapdown(q, pos*2+2);
        }
    }
}

void enqueue(queue q, edgeptr e){
    q->data[q->last] = e;
    reheapup(q, q->last);
    q->last++;
}

edgeptr dequeue(queue q){
    edgeptr temp = q->data[0];
    q->last--;
    q->data[0] = q->data[q->last];
    reheapdown(q, 0);
    return temp;
}

void replaceDisjoin(int disjoinSet[], int size, int from, int to){
    int i = 0;
    for(i = 0; i < size; i++){
        if(disjoinSet[i] == from){
            disjoinSet[i] = to;
        }
    }
}

int main(){
    int adjMartix[SIZE][SIZE];
    int disjoinSet[SIZE];
    int n,m;
    char s,d;
    int w;
    int i,j,isALL;
    queue edgeList = (queue)malloc(sizeof(struct qu));
    edgeptr e;
    edgeList->last = 0;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        scanf(" %c %c %d", &s, &d, &w);
        e = (edgeptr)malloc(sizeof(struct edge));
        e->so = s - 'a';
        e->dis = d - 'a';
        e->w = w;
        enqueue(edgeList, e);
    }

    for(i = 0; i < n; i++){
        disjoinSet[i] = i;
    }

    while(edgeList->last > 0){
        e = dequeue(edgeList);
        if(disjoinSet[e->so] != disjoinSet[e->dis]){
            adjMartix[e->so][e->dis] = e->w;
            adjMartix[e->dis][e->so] = e->w;
            if(disjoinSet[e->so] < disjoinSet[e->dis]){
                replaceDisjoin(disjoinSet, n, disjoinSet[e->dis], disjoinSet[e->so]);
            }else{
                replaceDisjoin(disjoinSet, n, disjoinSet[e->so], disjoinSet[e->dis]);
            }
        }
        free(e);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", adjMartix[i][j]);
        }
        printf("\n");
    }
}
