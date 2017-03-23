#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

typedef std::pair<int,int> PII;

int n,k,a,b,c;
long long mx;
std::vector<PII> edge[10005];
int exA[15],exB[15],exC[15];
//select
long long dynS[10005];
//not select
long long dynN[10005];
bool isSe[10005];

void solve(int x, int o){
	//dynamic on tree
	dynN[x] = 0;
	for(PII pi : edge[x]){
		if(pi.first!=o){
			solve(pi.first,x);
			dynN[x] += dynS[pi.first];
		}
	}
	dynS[x] = dynN[x];
	
	//find dynS
	if(!isSe[x]){
		for(PII pi : edge[x]){
			if(pi.first!=o&&!isSe[pi.first]){
				dynS[x] = std::max(dynS[x], dynN[x] - dynS[pi.first] + dynN[pi.first] + pi.second);
			}
		}
	}else{
		dynN[x] = -INF;
	}
}

void recurK(int x, int sumC){
	if(x==k){
		solve(1,0);
		mx = std::max(mx,dynS[1]+sumC);
	}else{
		//not select
		recurK(x+1, sumC);
		//select
		if(!isSe[exA[x]]&&!isSe[exB[x]]){
			isSe[exA[x]] = true;
			isSe[exB[x]] = true;
			recurK(x+1, sumC+exC[x]);
			isSe[exA[x]] = false;
			isSe[exB[x]] = false;
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i < n; i++){
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
	}
	for(int i = 0; i < k; i++){
		scanf("%d%d%d",&exA[i],&exB[i],&exC[i]);
	}

	recurK(0,0);
	printf("%lld\n", mx);
}