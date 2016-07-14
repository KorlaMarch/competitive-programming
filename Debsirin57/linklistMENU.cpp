#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

#define DEBUG 0

struct node
 { int data;
   struct node *next;
 };
typedef struct node *NODEPTR;

NODEPTR getnode(void);

NODEPTR getnode(void)
{ NODEPTR p;
  p=(NODEPTR) malloc(sizeof(struct node));
  return p;
}

void del_list(NODEPTR head){
    if(head == NULL){
        return;
    }else{
        del_list(head->next);
        printf("Del : %d\n", head->data);
        free(head);
    }
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

int compare(int a, int b){ return a < b ? 1 : 0; }

NODEPTR insSort(NODEPTR head, int data){
    NODEPTR q = head;

    if(q == NULL){
        NODEPTR q = getnode();
        q->data = data;
        q->next = NULL;
        head = q;
    }else{
        if(compare(data, q->data)){
            head = insFront(head, data);
        }else{
            for(;q->next != NULL && !compare(data, q->next->data);q = q->next);
            insList(q, data);
        }
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

NODEPTR delNode(NODEPTR head, int data){
    NODEPTR q, p;
    if(data == head->data){
        q = head;
        head = head->next;
        free(q);
    }else{
        for(q = head; q->next != NULL && q->next->data != data; q = q->next);
        if(q->next == NULL){
            printf("Not Found!\n");
        }else{
            p = q->next;
            q->next = q->next->next;
            free(p);
        }
    }
    return head;


}

int main()
{
   int order,x;
   struct node *head = NULL;
   for(;;)
	{
	    if(!DEBUG){
	     printf("|| LINKLIST ||\n");
	     printf("1.create list\n");
	     printf("2.insert node\n");
	     printf("3.remove node\n");
	     printf("4.print list\n");
	     printf("5.exit\n");
	     printf("order : ");} scanf("%d",&order);
	     switch(order)
		  {
		       case 1:
		           if(head != NULL){
                        getchar();
                        if(!DEBUG)
                        printf("List already exits. Want to delete? (y/n) ");
                        x = getchar();
                        if(x == 'y'){
                            del_list(head);
                        }
		           }
		           break;
		       case 2:
		           if(!DEBUG)
		           printf("Enter Data : "); scanf("%d", &x);
		           head = insSort(head, x);
		           break;
		       case 3:
		           if(!DEBUG)
		           printf("Enter Node Data : "); scanf("%d",&x);
		           head = delNode(head, x);
                   break;
		       case 4:
		           printf("List : "); print_list(head);
		           break;
		       case 5:
		           return 0;
		  }
		  //getch();
		  //system("cls");
            printf("\n");
	}
}
