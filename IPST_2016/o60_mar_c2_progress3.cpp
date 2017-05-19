#include "stdio.h"
#include "set"
#include "map"
#include "algorithm"

typedef std::pair<int,int> PII;
#define INF 1000000000

int n,m,a,b;
int v[100005];
int fen[100005];
int mx[400005];
int mn[400005];
int lazy[400005];
int cinit[100005];
int ans[100005];

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

void makeSeg(int no, int i, int j){
	if(i==j){
		mx[no] = cinit[i];
		mn[no] = cinit[i];
	}else{
		makeSeg(no*2+1,i,i+(j-i)/2);
		makeSeg(no*2+2,i+(j-i)/2+1,j);
		mx[no] = std::max(mx[no*2+1],mx[no*2+2]);
		mn[no] = std::min(mn[no*2+1],mn[no*2+2]);
	}
}

void addSeg(int no, int i, int j, int x, int y, int v){
	if(i==j){
		mx[no] += lazy[no]+v;
		mn[no] += lazy[no]+v;
		lazy[no] = 0;
		return;
	}
	
	//subseq
	if(x<=i&&j<=y){
		lazy[no] += v;
		mx[no] = std::max(mx[no*2+1],mx[no*2+2])+lazy[no];
		mn[no] = std::min(mn[no*2+1],mn[no*2+2])+lazy[no];
		return;
	}

	if(lazy[no]){
		lazy[no*2+1] += lazy[no];
		lazy[no*2+2] += lazy[no];
		lazy[no] = 0;
	}

	if(isIntersect(x,y,i,i+(j-i)/2)) addSeg(no*2+1,i,i+(j-i)/2,x,y,v);
	if(isIntersect(x,y,i+(j-i)/2+1,j)) addSeg(no*2+2,i+(j-i)/2+1,j,x,y,v);

	mx[no] = std::max(mx[no*2+1],mx[no*2+2]);
	mn[no] = std::min(mn[no*2+1],mn[no*2+2]);
}

int getSegMn(int no, int i, int j, int x, int y){
	if(i==j){
		mx[no] += lazy[no];
		mn[no] += lazy[no];
		lazy[no] = 0;
		return mn[no];
	}
	
	//subseq
	if(x<=i&&j<=y){
		return mn[no];
	}

	if(lazy[no]){
		lazy[no*2+1] += lazy[no];
		lazy[no*2+2] += lazy[no];
		lazy[no] = 0;
	}

	int minv = INF;
	if(isIntersect(x,y,i,i+(j-i)/2)) minv = std::min(minv,getSegMn(no*2+1,i,i+(j-i)/2,x,y));
	if(isIntersect(x,y,i+(j-i)/2+1,j)) minv = std::min(minv,getSegMn(no*2+1,i+(j-i)/2+1,j,x,y));

	return minv;
}

int getSegMx(int no, int i, int j, int x, int y){
	if(i==j){
		mx[no] += lazy[no];
		mn[no] += lazy[no];
		lazy[no] = 0;
		return mx[no];
	}
	
	//subseq
	if(x<=i&&j<=y){
		return mx[no];
	}

	if(lazy[no]){
		lazy[no*2+1] += lazy[no];
		lazy[no*2+2] += lazy[no];
		lazy[no] = 0;
	}

	int maxv = -INF;
	if(isIntersect(x,y,i,i+(j-i)/2)) maxv = std::max(maxv,getSegMx(no*2+1,i,i+(j-i)/2,x,y));
	if(isIntersect(x,y,i+(j-i)/2+1,j)) maxv = std::max(maxv,getSegMx(no*2+1,i+(j-i)/2+1,j,x,y));

	return maxv;
}

void addAns(int no, int i, int j, int x, int y){

}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
	}

	//init gsum
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];
		cinit[i] = sum;
	}
	makeSeg(0,0,n);

	printf("%d\n",ans[0]);

	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		const int ch = b-v[a];
		addSeg(0,0,n,a,n,ch);
		v[a] = b;

		int newAns = getSegMx(0,0,n,a,n)-getSegMn(0,0,n,0,a);
		if(){

		}

		printf("%d\n",ans[0]);
	}
}