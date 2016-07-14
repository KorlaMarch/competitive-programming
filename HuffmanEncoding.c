#include "stdio.h"
#include "stdlib.h"

struct node{
    int sum;
    char c;
    struct node* rnode;
    struct node* lnode;
};

typedef struct node* nodeptr;

struct qu{
    nodeptr data[100];
    int last;
};

typedef struct qu* priorityQueue;

void reheapUp(priorityQueue q, int pos){
    nodeptr temp;
    if(pos <= 0){
        return;
    }
    if(q->data[pos]->sum < q->data[(pos-1)/2]->sum){
        temp = q->data[pos];
        q->data[pos] = q->data[(pos-1)/2];
        q->data[(pos-1)/2] = temp;
        reheapUp(q, (pos-1)/2);
    }
}

void reheapDown(priorityQueue q, int pos){
    nodeptr temp;
    if(pos*2+1 >= q->last){
        return;
    }
    if(q->data[pos*2+1]->sum < q->data[pos*2+2]->sum){
        if(q->data[pos*2+1]->sum < q->data[pos]->sum){
            temp = q->data[pos];
            q->data[pos] = q->data[pos*2+1];
            q->data[pos*2+1] = temp;
            reheapDown(q, pos*2+1);
        }
    }else{
        if(q->data[pos*2+2]->sum < q->data[pos]->sum){
            temp = q->data[pos];
            q->data[pos] = q->data[pos*2+2];
            q->data[pos*2+2] = temp;
            reheapDown(q, pos*2+2);
        }
    }
}

void enqueue(priorityQueue q, nodeptr data){
    q->data[q->last] = data;
    reheapUp(q, q->last);
    q->last++;
}

nodeptr dequeue(priorityQueue q){
    nodeptr temp = q->data[0];
    q->data[0] = q->data[q->last-1];
    q->last--;
    reheapDown(q, 0);
    return temp;
}

int treeMapping(int map[], int count[], nodeptr root, int n, int d){
    if(root == NULL){
        return;
    }
    if(root->c != '\0'){
        map[root->c] = n;
        count[root->c] = d;
    }else{
        treeMapping(map,count,root->lnode, n << 1, d+1);
        treeMapping(map,count,root->rnode, (n << 1)|0x01, d+1);
    }
}

nodeptr encode(char filename[], char outname[]){
    int i,j,k;
    char t,c;
    FILE* rawdata = fopen(filename, "r");
    FILE* outdata;
    int feq[256] = {};
    int map[256] = {};
    int count[256] = {};
    char buffer[1024];
    nodeptr temp,root;
    priorityQueue queue = (priorityQueue) malloc(sizeof(struct qu));
    queue->last = 0;
    //make feq
    while(!feof(rawdata)){
        fgets(buffer, 1024, rawdata);
        for(i = 0; buffer[i] != '\0'; i++){
            feq[buffer[i]]++;
        }
    }
    fclose(rawdata);

    //make feq tree
    for(i = 0; i < 256; i++){
        if(feq[i]){
            temp = (nodeptr)malloc(sizeof(struct node));
            temp->sum = feq[i];
            temp->c = i;
            temp->rnode = NULL;
            temp->lnode = NULL;
            enqueue(queue, temp);
            printf("%c %d\n", i, feq[i]);
        }

    }
    for(i = 0; i < queue->last; i++){
        printf("%d\n", queue->data[i]->sum);
    }
    //printf("%d\n", queue->last);
    //return;
    while(queue->last > 1){
        //printf("f\n");
        temp = (nodeptr)malloc(sizeof(struct node));
        temp->c = '\0';
        temp->lnode = dequeue(queue);
        temp->rnode = dequeue(queue);
        temp->sum = temp->lnode->sum + temp->rnode->sum;
        enqueue(queue, temp);
        //printf("%d %d %d\n", temp->lnode->sum,temp->rnode->sum, temp->sum);
    }

    root = dequeue(queue);

    //mapping char
    treeMapping(map, count, root, 0, 0);

    //encode and output
    i = 0;
    t = 0;
    for(i = 0; i < 256; i++){
        if(feq[i] != 0) printf("%c %d %x %d\n", i, feq[i], map[i], count[i]);
    }
    outdata = fopen(outname, "w");
    rawdata = fopen(filename, "r");
    while(!feof(rawdata)){
        //printf("loop");
        c = fgetc(rawdata);//printf("count c = %d %d\n", c, count[c]);
        if(c != EOF){
        k = map[c];
        for(j = count[c] - 1; j >= 0; j--, i++){
            printf("%d", (k>>j)&0x01);
            fputc(((k>>j)&0x01)+'0', outdata);
        }
        }
    }
    fclose(outdata);
}

int main(){
    encode("war.txt", "encode.txt");
}
