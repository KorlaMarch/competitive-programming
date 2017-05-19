#include "stdio.h"
#include "vector"
#include "algorithm"

typedef std::pair<int,int> PII;
typedef std::pair<int, long long> PILL;
struct Node{
	int nc;
	long long sum;
	struct Node* left;
	struct Node* right;
	Node(int _nc = 0, long long _sum = 0) : nc(_nc), sum(_sum) {
		left = nullptr;
		right = nullptr;
	}
};

int n,m,s,t;
double u;
PII a[100005];
std::vector<Node*> head;

Node* makeseg(int x, int y){
	Node* no = new Node();
	if(x!=y){
		no->left = makeseg(x,x+(y-x)/2);
		no->right = makeseg(x+(y-x)/2+1,y);
	}
	return no;
}

Node* addseg(Node* old, int pos, int v, int x, int y){
	Node* no = new Node(old->nc+1,old->sum+v);
	if(x!=y){
		if(pos<=x+(y-x)/2){
			no->left = addseg(old->left,pos,v,x,x+(y-x)/2);
			no->right = old->right;
		}else{
			no->left = old->left;
			no->right = addseg(old->right,pos,v,x+(y-x)/2+1,y);
		}
	}
	return no;
}

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

PILL getseg(Node* no, int i, int j, int x, int y){
	if(x<=i&&j<=y){
		return {no->nc,no->sum};
	}else if(isIntersect(i,j,x,y)){
		PILL pi,re;
		pi = getseg(no->left,i,i+(j-i)/2,x,y);
		re = getseg(no->right,i+(j-i)/2+1,j,x,y);
		pi.first += re.first;
		pi.second += re.second;
		return pi;
	}
	return {0,0LL};
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	std::sort(a,a+n);
	head.push_back(makeseg(0,n-1));
	for(int i = n-1; i >= 0; i--){
		head.push_back(addseg(head.back(),a[i].second,a[i].first,0,n-1));
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d%lf",&s,&t,&u);
		int x = 0, y = head.size()-1;
		int lm = -1;
		while(x<=y){
			int m = (x+y)/2;
			PILL re = getseg(head[m],0,n-1,s-1,t-1);
			if(re.first==0){
				x = m+1;
			}else if(re.second/(double)re.first>=u){
				lm = re.first;
				x = m+1;
			}else{
				y = m-1;
			}
		}
		if(lm==-1) printf("-1\n");
		else printf("%d\n",t-s+1-lm);
	}
}