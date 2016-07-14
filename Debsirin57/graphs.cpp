#include "stdio.h"
#include "stdlib.h"

#define SIZE 50

///////////////////////////////////// Queue /////////////////////////////
struct node{
    int data;
    struct node *next;
};

typedef struct node* NODEPTR;

struct qu{
    NODEPTR head;
    NODEPTR rear;
    int size;
};

typedef qu* queue;


NODEPTR getnode(){
    return (NODEPTR)malloc(sizeof(struct node));
}

queue createQueue(){
    queue q = (queue)malloc(sizeof(struct qu));
    q->head = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queue q, int data){
    NODEPTR n = getnode();
    n->next = NULL;
    n->data = data;
    if(q->size <= 0){
        q->rear = n;
        q->head = n;
    }else{
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
}

int dequeue(queue q){
    if(q->size <= 0){
        return -1;
    }
    NODEPTR no = q->head;
    int d = no->data;
    q->head = q->head->next;
    q->size--;
    free(no);
    return d;
}

/////////////////////////////////////////////////////////////////////////


void DFSTravelsal(int adj[SIZE][SIZE], int size, int nodeIndex){
    adj[nodeIndex][nodeIndex] = 1;
    printf("%c ", nodeIndex + 'a');
    for(int i = 0; i < size; i++){
        if(adj[i][i] != 1 && adj[nodeIndex][i] != -1){
            DFSTravelsal(adj, size, i);
        }
    }
}

void BFSTravelsal(int adj[SIZE][SIZE], int size){
    queue q = createQueue();
    int n;
    enqueue(q, 0);
    adj[0][0] = 1;
    while(q->size > 0){
        n = dequeue(q);
        printf("%c ", n + 'a');

        for(int i = 0; i < size; i++){
            if(adj[i][i] != 1 && adj[n][i] != -1){
                adj[i][i] = 1;
                enqueue(q, i);
            }
        }
    }
    return;
}

void clearSigned(int adj[SIZE][SIZE], int size){
    for(int i = 0; i < size; i++){
        adj[i][i] = -1;
    }
}

void topologicalSort(int adj[SIZE][SIZE]){
    int inEdge[SIZE] = {};
    queue exlist = createQueue();
    bool isFind;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(adj[j][i] > 0){
                inEdge[i]++;
            }
        }
    }
    for
    //find zero and enqueue
    for(int j = 0; j < n; j++){

    }
}

//////////////////////////////////////////////////////

int main(){
    int adjMatrix[SIZE][SIZE];
    int n;
    char c1, c2;
    int w;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            adjMatrix[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        while(1){
            c1 = getchar();
            if(c1 >= 'a' && c1 <= 'z'){
                break;
            }
        }

        while(1){
            c2 = getchar();
            if(c2 >= 'a' && c2 <= 'z'){
                break;
            }
        }

        scanf("%d", &w);
        printf("%c %c %d\n", c1, c2, w);
        adjMatrix[c1 - 'a'][c2 - 'a'] = w;
        adjMatrix[c2 - 'a'][c1 - 'a'] = w;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\nDFS-Travelsal: ");
    DFSTravelsal(adjMatrix, n, 0);
    clearSigned(adjMatrix, n);
    printf("\nBFS-Travelsal: ");
    BFSTravelsal(adjMatrix, n);
}
