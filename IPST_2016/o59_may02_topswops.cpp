#include "stdio.h"
#include "algorithm"

struct Node{
	struct Node *l,*r; 
	int v;
	bool isSwap;

	Node(int _v = 0) : v(_v){
		l = nullptr;
		r = nullptr;
		isSwap = false;
	}
};

int n,m;
int x[525005];
Node* head;

void makeseg(Node*& no, int i, int j){
	if(i==j){
		no = new Node(x[i]);
	}else{
		no = new Node();
		makeseg(no->l, i, i+(j-i)/2);
		makeseg(no->r, i+(j-i)/2+1, j);
	}
}

int getfirst(Node* no){
	if(no->isSwap){
		std::swap(no->l,no->r);
		no->isSwap = false;
		if(no->l) no->l->isSwap = !no->l->isSwap;
		if(no->r) no->r->isSwap = !no->r->isSwap;
	}

	if(no->l) return getfirst(no->l);
	else return no->v;
}

void doswap(Node*& no, int i, int j, int y){

}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x[i]);
	}
	//cal new n(m)
	for(int m = 1; m < n; m *= 2);

	makeseg(head, 0, m-1);

	int co;
	for(co = 0; ; co++){
		int fir = getfirst(head);
		if(fir==1) break;
		doswap(head, 0, m-1, fir-1);
	}

	printf("%d\n",co);
}