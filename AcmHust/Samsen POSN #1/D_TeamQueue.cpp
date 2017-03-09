#include "stdio.h"
#include "stdlib.h"

struct node{
	int num;
	struct node* prev;
};

typedef node* Nodeptr;

Nodeptr createNode(int num){
	Nodeptr temp = (Nodeptr) malloc(sizeof(node));
	temp->num = num;
	temp->prev = NULL;
	return temp;
}

int t,n,x;
char op[100];
int team[1000005];
Nodeptr front,back;
Nodeptr backT[1005];

void clearData(){
	Nodeptr temp;
	for(int i = 0; i < t; i++) backT[i] = NULL;
	back = NULL;
	while(front != NULL){
		temp = front;
		front = front->prev;
		free(temp);
	}
}



int main(){
	for(int k = 1; ; k++){
		scanf("%d",&t);
		if(t==0) break;
		clearData();
		for(int i = 0; i < t; i++){
			scanf("%d",&n);
			for(int j = 0; j < n; j++){
				scanf("%d",&x);
				team[x] = i;
			}
		}
		printf("Scenario #%d\n",k);
		while(1){
			scanf(" %s", op);
			if(op[0]=='E'){
				scanf("%d",&x);
				Nodeptr nodeX = createNode(x);
				if(backT[team[x]]!=NULL){
					nodeX->prev = backT[team[x]]->prev;
					backT[team[x]]->prev = nodeX;
					if(backT[team[x]]==back){
						back = nodeX;
					}
					backT[team[x]] = nodeX;
				}else{
					backT[team[x]] = nodeX;
					if(back==NULL){
						back = front = nodeX;
					}else{
						back->prev = nodeX;
						back = nodeX;
					}
				}
			}else if(op[0]=='D'){
				Nodeptr temp = front;
				printf("%d\n",front->num);
				if(backT[team[front->num]]==front){
					backT[team[front->num]] = NULL;
				}
				front = front->prev;
				free(temp);

				if(front==NULL){
					back = NULL;
				}
			}else{
				break;
			}
		}

		printf("\n");
	}
}