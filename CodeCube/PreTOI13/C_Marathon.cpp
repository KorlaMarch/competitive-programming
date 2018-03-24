#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

#define INF 100000000005LL
typedef std::pair<long long, int> PII;

struct Edge{
	int v,d,t;
};

int n,m,k,ui,vi,di,ti,pi,si;
long long t;
std::vector<Edge> edge[100005];
int minP[100005];
std::priority_queue<PII,std::vector<PII>,std::greater<PII>> qu;
long long minDis[100005];

void pushQu(long long ti, int xi){
	if(ti<minDis[xi]){
		minDis[xi] = ti;
		qu.push({ti,xi});
	}
}

bool canDo(int x){
	while(!qu.empty()) qu.pop();
	for(int i = 1; i <= n; i++) minDis[i] = INF;
	pushQu(1,1);
	while(!qu.empty()){
		PII pi = qu.top();
		qu.pop();

		if(pi.second==n){
			return pi.first-1<=t;
		}

		if(pi.first!=minDis[pi.second]) continue;

		for(Edge ed : edge[pi.second]){
			if(ed.d<=x){
				pushQu(pi.first+ed.t,ed.v);
			}
		}
	}

	return false;
}

int main(){
	scanf("%d%d%d%lld",&n,&m,&k,&t);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d%d",&ui,&vi,&di,&ti);
		edge[ui].push_back({vi,di,ti});
		edge[vi].push_back({ui,di,ti});
	}

	for(int i = 0; i < 100005; i++) minP[i] = 10000000;

	for(int i = 0; i < k; i++){
		scanf("%d%d",&pi,&si);
		minP[si] = std::min(minP[si],pi);
	}

	for(int i = 100000; i >= 0; i--){
		minP[i] = std::min(minP[i],minP[i+1]);
	}

	int x=1,y=100000,m,lm=-1;
	
	while(x<=y){
		m = (x+y)/2;
		if(canDo(m)){
			y = m-1;
			lm = m;
		}else{
			x = m+1;
		}
	}

	if(lm==-1||minP[lm]==10000000){
		printf("-1\n");
	}else{
		printf("%d\n",minP[lm]);
	}
}