#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

struct node{
    int data;
    struct node* next;
};

typedef struct node* NODEPTR;

int compare(int a, int b){ return a > b ? 1 : 0; }

NODEPTR getnode(){
    return (NODEPTR) malloc(sizeof(struct node));
}

void del_list(NODEPTR head){
    if(head == NULL){
        return;
    }else{
        del_list(head->next);
        free(head);
    }
}

NODEPTR getback(NODEPTR head){
    NODEPTR q;
    for(q = head; q->next != NULL; q = q->next);
    return q;
}

int length(NODEPTR head){
    int l;
    for(l = 0; head != NULL; head = head->next, l++);
    return l;
}

NODEPTR insList(NODEPTR head, int data){
    NODEPTR q = getnode();
    q->data = data;
    q->next = head->next;
    head->next = q;
    return head;
}

NODEPTR insFront(NODEPTR head, int data){
    NODEPTR q = getnode();
    q->data = data;
    q->next = head;
    head = q;
    return head;
}

NODEPTR insBack(NODEPTR head, int data){
    if(head == NULL){
        /*head = getnode();
        head->data = data;
        head->next = NULL;*/
        head = insFront(head, data);
    }else{
        insList(getback(head), data);
    }
    return head;
}

NODEPTR getKNode(NODEPTR head, int k){
    for(; k > 0 && head != NULL; k--, head = head->next);
    return head;
}

NODEPTR insSort(NODEPTR head, int data){
    NODEPTR q = head;

    if(q == NULL){
        head = insBack(head, data);
    }else{
        for(;q->next != NULL && compare(data, q->next->data);q = q->next);
        insList(q, data);
    }
    return head;
}

int print_list(NODEPTR head){
    NODEPTR q;
    if(head != NULL){
        for(q = head; q != NULL; q = q->next){
            printf("%d ", q->data);
        }
    }else{
        printf("NULL");
    }
    printf("\n");
}

int main(){
    NODEPTR head = NULL;
    NODEPTR q;
    int n = 0;
    int m, k;

    //menu
    /*while(1){
        system("cls");
        printf("List : ");
        print_list(head);
        printf("Length : %d\n", length(head));
        printf("\t======Enter mode======\n\t1:Insert Back \n\t2:Insert Front \n\t3:Insert At\n\t4:Sorting\n\t5:Stop\n");
        scanf("%d", &m);
        system("cls");
        if(m == 1){
            printf("Enter Value : ");
            scanf("%d", &n);
            head = insSort(head, n);
        }else if(m == 2){
            printf("Enter Value : ");
            scanf("%d", &n);
            head = insFront(head, n);
        }else if(m == 3){
            printf("Enter Pos : ");
            scanf("%d", &k);
            printf("Enter Value : ");
            scanf("%d", &n);
            q = getKNode(head, k);
            if(q == NULL){
                printf("Error!");
            }else{
                insList(q, n);
            }
        }else if(m == 4){

        }else if(m == 5){
            system("exit");
        }else{
            printf("Error!\n");
        }
        //getch();
    }*/

    while(scanf("%d", &n) && n != -1){
        head = insSort(head, n);
    }
    print_list(head);
}
