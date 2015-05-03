#include "stdio.h"
#include "stdlib.h"

struct n{
    int x;
    int y;
    int t;
};

typedef struct n node;

struct heap{
    node data[1000];
    int last;
};

typedef struct heap* queue;

void swap(node* a, node* b){
    node n = *a;
    *a = *b;
    *b = n;
}

void reheapup(queue q, int pos){
    if(pos <= 0){
        return;
    }
    if(q->data[pos].t < q->data[(pos-1)/2].t){
        swap(&q->data[pos],&q->data[(pos-1)/2]);
        reheapup(q, (pos-1)/2);
    }
}

void reheapdown(queue q, int pos){
    if(pos*2+1 >= q->last){
        return;
    }
    if(pos*2+2 == q->last || q->data[pos*2+1].t < q->data[pos*2+2].t){
        if(q->data[pos].t > q->data[pos*2+1].t){
            swap(&q->data[pos], &q->data[pos*2+1]);
            reheapdown(q, pos*2+1);
        }
    }else{
        if(q->data[pos].t > q->data[pos*2+2].t){
            swap(&q->data[pos], &q->data[pos*2+2]);
            reheapdown(q, pos*2+2);
        }
    }
}

void enqueue(queue q, node data){
    q->data[q->last] = data;
    reheapup(q, q->last);
    q->last++;
}

node dequeue(queue q){
    q->last--;
    swap(&q->data[0], &q->data[q->last]);
    reheapdown(q, 0);
    return q->data[q->last+1];
}

int main(){
    int m,n;
    int i,j;
    int castle[100][100];
    int dynmap[100][100];
    queue heap = (queue)malloc(sizeof(struct heap));
    node no, no2,obj;
    int fcount;
    for(fcount = 0; fcount < 1; fcount++){
        heap->last = 0;
        scanf("%d%d", &m, &n);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                dynmap[i][j] = -1;
            }
        }
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &castle[i][j]);
            }
        }
        scanf("%d%d%d", &obj.x, &obj.y, &obj.t);
        obj.x--;
        obj.y--;
        //shortest part
        no.x = 0;
        no.y = 0;
        no.t = castle[0][0];
        dynmap[0][0] = castle[0][0];
        enqueue(heap, no);
        while(heap->last > 0){
            no = dequeue(heap);
            castle[no.x][no.y] = -1;
            if(no.t >= dynmap[obj.x][obj.y] && dynmap[obj.x][obj.y] != -1){
                break;
            }
            if(no.x-1 >= 0 && castle[no.x-1][no.y] != -1 &&
               (dynmap[no.x-1][no.y] == -1 || no.t+castle[no.x-1][no.y] < dynmap[no.x-1][no.y])){
                no2.x = no.x-1;
                no2.y = no.y;
                no2.t = no.t+castle[no.x-1][no.y];
                dynmap[no.x-1][no.y] = no2.t;
                enqueue(heap, no2);
            }

            if(no.y-1 >= 0 && castle[no.x][no.y-1] != -1 &&
               (dynmap[no.x][no.y-1] == -1 || no.t+castle[no.x][no.y-1] < dynmap[no.x][no.y-1])){
                no2.x = no.x;
                no2.y = no.y-1;
                no2.t = no.t+castle[no.x][no.y-1];
                dynmap[no.x][no.y-1] = no2.t;
                enqueue(heap, no2);
            }

            if(no.x+1 < n && castle[no.x+1][no.y] != -1 &&
               (dynmap[no.x+1][no.y] == -1 || no.t+castle[no.x+1][no.y] < dynmap[no.x+1][no.y])){
                no2.x = no.x+1;
                no2.y = no.y;
                no2.t = no.t+castle[no.x+1][no.y];
                dynmap[no.x+1][no.y] = no2.t;
                enqueue(heap, no2);
            }

            if(no.y+1 < m && castle[no.x][no.y+1] != -1 &&
               (dynmap[no.x][no.y+1] == -1 || no.t+castle[no.x][no.y+1] < dynmap[no.x][no.y+1])){
                no2.x = no.x;
                no2.y = no.y+1;
                no2.t = no.t+castle[no.x][no.y+1];
                dynmap[no.x][no.y+1] = no2.t;
                enqueue(heap, no2);
            }
        }
        printf("%d\n", dynmap[obj.x][obj.y]);
    }
}
