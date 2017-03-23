#include "stdio.h"
#include "algorithm"
#include "vector"

typedef std::pair<int,int> PII;

int n,m,x,y,k;
int a[100005];
PII sorted[100005];
std::vector<PII> fen[100005];

void addFen(int x, int v, int ver){
	for(; x <= n; x += (x&-x)){
		fen[x].push_back({ver,fen[x].back().second+v});
	}
}

bool cmp(PII val, PII f){
	return val.first<f.first;
}

int getFen(int x, int ver){
	int v = 0;
	for(; x > 0; x -= (x&-x)){
		PII val = {ver,0};
		v += (std::upper_bound(fen[x].begin(),fen[x].end(),val,cmp)-1)->second;
	}
	return v;
}

int binarySearch(int i, int j, int k){
	int x = 1, y = n, m, lm;
	while(x<=y){
		m = (x+y)/2;
		if(getFen(j,m)-getFen(i-1,m)>=k){
			//if work
			lm = m;
			y = m-1;
		}else{
			x = m+1;
		}
	}
	return lm;
}

int main(){
	scanf("%d%d",&n,&m);

	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		sorted[i-1] = {a[i],i};
		fen[i].push_back({0,0});
	}

	std::sort(sorted,sorted+n);

	for(int i = 0; i < n; i++){
		addFen(sorted[i].second,1,i+1);
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",sorted[binarySearch(x,y,k)-1].first);
	}


}