#include "stdio.h"
#include "set"
#include "map"
#include "algorithm"

typedef std::pair<int,int> PII;

int n,m,a,b;
int v[100005];
int fen[100005];
int mx[400005];
int mn[400005]
int lazy[400005];
int cinit[100005];
std::map<int,int> group;

void addFen(int x, int v){
	x++;
	for(; x <= n; x+=(x&-x)){
		fen[x] += v;
	}
}

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

int getFen(int x){
	x++;
	int v = 0;
	for(; x > 0; x-=(x&-x)){
		v += fen[x];
	}
	return v;
}

void makeSeg(int no, int i, int j){
	if(i==j){
		seg[no] = cinit[i];
	}else{
		makeSeg(no*2+1,i,i+(j-i)/2);
		makeSeg(no*2+2,i+(j-i)/2+1,j);
		seg[no] = std::max(seg[no*2+1],seg[no*2+2]);
	}
}

void addSeg(int no, int i, int j, int x, int y, int v){
	if(i==j){
		seg[no] += lazy[no]+v;
		lazy[no] = 0;
		return;
	}
	
	//subseq
	if(x<=i&&j<=y){
		lazy[no] += v;
		seg[no] = std::max(seg[no*2+1],seg[no*2+2])+lazy[no];
		return;
	}

	if(lazy[no]){
		lazy[no*2+1] += lazy[no];
		lazy[no*2+2] += lazy[no];
		lazy[no] = 0;
	}

	if(isIntersect(x,y,i,i+(j-i)/2)) makeSeg(no*2+1,i,i+(j-i)/2);
	if(isIntersect(x,y,i+(j-i)/2+1,j)) makeSeg(no*2+2,i+(j-i)/2+1,j);
	seg[no] = std::max(seg[no*2+1],seg[no*2+2]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
		addFen(i,v[i]);
	}

	//init gsum
	int sum = 0;
	int lbg = 0;
	for(int i = 0; i < n; i++){
		if(sum<0){
			group[lbg] = sum;
			sum = 0;
			lbg = i;
		}
		sum += v[i];
		cinit[i] = sum;
	}
	group[lbg] = sum;
	makeSeg(0,0,n);

	printf("%d\n",seg[0]);

	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		const int ch = b-v[a];
		auto it = group.upper_bound(a);
		it--;

		if(ch<0){
			if(getFen(a)-getFen(it->first-1)<0){

			}else{

			}
		}else if(ch>0){

		}

		v[a] = b;

		printf("%d\n",seg[0]);
	}
}