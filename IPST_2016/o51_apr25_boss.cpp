#include "stdio.h"
#include "algorithm"
#include "map"

struct nodeT{
	int id;
	nodeT *right,*left,*parent,*path_parent;
	nodeT(int _id = 0){
		id = _id;
		left = NULL;
		right = NULL;
		parent = NULL;
		path_parent = NULL;
	}
};

int n,m,o,a;
int p[100005];
nodeT* employ[100005];
// std::map<nodeT*,int> lookup;

// void printNode(nodeT* v){
// 	printf("Node : %d\n",v->id);
// 	printf("\tLeft : %d\n",lookup[v->left]);
// 	printf("\tRight : %d\n",lookup[v->right]);
// 	printf("\tParent : %d\n",lookup[v->parent]);
// 	printf("\tPath : %d\n",lookup[v->path_parent]);
// }

// void printTree(){
// 	for(int i = 1; i <= n; i++){
// 		printNode(employ[i]);
// 	}
// }

void rotateRight(nodeT* v){
	nodeT* tmp = v->left;
	//Clockwise
	if(v->parent!=NULL){
		if(v->parent->left==v){
			v->parent->left = tmp;
		}else{
			v->parent->right = tmp;
		}
	}

	tmp->parent = v->parent;
	v->parent = tmp;
	v->left = tmp->right;
	if(tmp->right!=NULL){
		tmp->right->parent = v;
	}
	tmp->right = v;

	tmp->path_parent = v->path_parent;
	v->path_parent = NULL;
}

void rotateLeft(nodeT* v){
	nodeT* tmp = v->right;
	//Counter Clockwise
	if(v->parent!=NULL){
		if(v->parent->left==v){
			v->parent->left = tmp;
		}else{
			v->parent->right = tmp;
		}
	}

	tmp->parent = v->parent;
	v->parent = tmp;
	v->right = tmp->left;
	if(tmp->left!=NULL){
		tmp->left->parent = v;
	}
	tmp->left = v;

	tmp->path_parent = v->path_parent;
	v->path_parent = NULL;
}

void splay(nodeT* v){
	while(v->parent!=NULL){
		if(v->parent->parent==NULL){
			//single rotation
			if(v->parent->left==v){
				rotateRight(v->parent);
			}else{
				rotateLeft(v->parent);
			}
		}else if((v->parent->left==v)==(v->parent->parent->left==v->parent)){
			//Zig-Zig
			if(v->parent->left==v){
				rotateRight(v->parent->parent);
				rotateRight(v->parent);
			}else{
				rotateLeft(v->parent->parent);
				rotateLeft(v->parent);
			}
		}else{
			//Zig-Zag
			if(v->parent->left==v){
				rotateRight(v->parent);
				rotateLeft(v->parent);
			}else{
				rotateLeft(v->parent);
				rotateRight(v->parent);
			}
		}
	}
}

nodeT* travelLeft(nodeT* no){
	if(no->left==NULL) return no;
	else return travelLeft(no->left);
}

void access(nodeT* no){
	// printf("access %d\n",no->id);
	nodeT *w,*v;
	v = no;
	splay(v);
	
	//clear v preferrend child
	if(v->right!=NULL){
		v->right->path_parent = v;
		v->right->parent = NULL;
		v->right = NULL;
	}

	while(v->path_parent!=NULL){
		w = v->path_parent;

		splay(w);

		//clear w preferrend child
		if(w->right!=NULL){
			w->right->path_parent = w;
			w->right->parent = NULL;
		}

		w->right = v;
		v->parent = w;
		v->path_parent = NULL;

		v = w;
	}
	splay(no);
}

// v must be root
// make v be a child of w
void link(nodeT* v, nodeT* w){
	//printf("link %d %d\n",v->id,w->id);
	access(v);
	access(w);
	v->left = w;
	w->parent = v;
}

//v must not be root
void cut(nodeT* v){
	access(v);
	v->left->parent = NULL;
	v->left = NULL;
}

nodeT* findRoot(nodeT* v){
	access(v);
	v = travelLeft(v);
	//printTree();
	splay(v);
	//printTree();
	return v;
}

int main(){
	scanf("%d%d",&n,&m);
	employ[1] = new nodeT(1);
	//lookup[employ[1]] = 1;
	for(int i = 2; i <= n; i++){
		scanf("%d",&p[i]);
		employ[i] = new nodeT(i);
		//lookup[employ[i]] = i;
	}

	for(int i = 2; i <= n; i++){
		link(employ[i],employ[p[i]]);
	}

	//printTree();

	for(int i = 0; i < m; i++){
		scanf("%d%d",&o,&a);
		if(o==1){
			//cut tree
			cut(employ[a]);
		}else if(o==2){
			//link tree
			link(employ[a],employ[p[a]]);
		}else{
			//find root
			if(a<1||a>n) printf("1\n");
			else printf("%d\n",findRoot(employ[a])->id);
		}
	}
}