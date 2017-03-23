#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

int t,n,a,b;
long long mx;
std::vector<int> ed[100005];
int xi[100005];
int si[100005];
long long maxAge[100005];

void solve(int x, int o){
	long long m1=-INF,m2=-INF;
	if(si[x]) maxAge[x] = xi[x];
	else maxAge[x] = -INF;
	for(int i : ed[x]){
		if(i!=o){
			solve(i,x);
			maxAge[x] = std::max(maxAge[x],maxAge[i]+xi[x]);

			if(maxAge[i]>=m1){
				m2 = m1;
				m1 = maxAge[i];
			}else if(maxAge[i]>m2){
				m2 = maxAge[i];
			}
		}
	}
	if(si[x]) mx = std::max(mx,maxAge[x]);
	mx = std::max(mx,m1+m2+xi[x]);
	//printf("MA %d : %d\n",x,maxAge[x]);
}

int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		for(int i = 0; i <= n; i++){
			ed[i].clear();
		}

		scanf("%d",&n);
		for(int i = 1; i < n; i++){
			scanf("%d%d",&a,&b);
			ed[a].push_back(b);
			ed[b].push_back(a);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d",&xi[i]);
		}
		
		for(int i = 1; i <= n; i++){
			scanf("%d",&si[i]);
		}

		mx = 0;
		solve(1,0);

		if(mx<=0) printf("Stay Home\n");
		else printf("%lld\n", mx);
	}
}