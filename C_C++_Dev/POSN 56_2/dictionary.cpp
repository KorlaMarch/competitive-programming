#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct node{
    char word[128];
    char meaning[512];
    struct node* lnode;
    struct node* rnode;
};

typedef struct node* nodeptr;

void addNodeDown(nodeptr root, nodeptr n){
    if(strcmp(n->word, root->word) >= 0){
        if(root->rnode == NULL){
            root->rnode = n;
        }else{
            addNodeDown(root->rnode, n);
        }
    }else{
        if(root->lnode == NULL){
            root->lnode = n;
        }else{
            addNodeDown(root->lnode, n);
        }
    }
    return;
}

nodeptr addNode(nodeptr root, char na[], char mean[]){
    nodeptr n = (nodeptr)malloc(sizeof(struct node));
    n->lnode = NULL;
    n->rnode = NULL;
    strcpy(n->word, na);
    strcpy(n->meaning, mean);
    if(root == NULL){
        root = n;
    }else{
        addNodeDown(root, n);
    }
    return root;
}

void BinarySearch(nodeptr root, char word[]){
    printf("%s ", root->word);
    if(root == NULL){
        printf("\nError!\n");
    }else{
        if(strcmp(word, root->word) == 0){
            printf("\nDEFINITION: %s\n\n", root->meaning);
        }else if(strcmp(word, root->word) > 0){
            BinarySearch(root->rnode, word);
        }else{
            BinarySearch(root->lnode, word);
        }
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int findHight(nodeptr root){
    if(root == NULL){
        return 0;
    }
    return 1+max(findHight(root->lnode),findHight(root->rnode));
}

void tarversal(nodeptr root){
    if(root->lnode != NULL){
        tarversal(root->lnode);
    }
    printf("%s\n", root);
    if(root->rnode != NULL){
        tarversal(root->rnode);
    }
    return;
}

int main(){

    char w[128];
    char m[512];
    nodeptr database = NULL;
    FILE* rawdata = fopen("dictionary.txt", "r");
    if(rawdata == NULL){
        printf("Reading data file fail\n");
        return -1;
    }

    while(!feof(rawdata)){
        fgets(w, 128, rawdata);
        if(w[0] != '\n'){
            fgets(m, 512, rawdata);
            w[strlen(w) - 1] = '\0';
            m[strlen(m) - 1] = '\0';
            //printf("Add Node : %s\n%s\n", w, m);
            database = addNode(database, w, m);
        }
    }
    fclose(rawdata);
    printf("Tree Hight = %d\n", findHight(database));
    //tarversal(database);
    while(1){
        printf("SEARCH? ");
        scanf(" %s", w);
        printf("VISIT: ");
        BinarySearch(database, w);
    }
}
