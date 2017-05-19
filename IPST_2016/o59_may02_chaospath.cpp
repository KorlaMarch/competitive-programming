#include "stdio.h"
#include "vector"
#include "algorithm"

int n,a,b;
long long ans;
std::vector<int> edge[100005];
int childC[100005];
long long cha[100005];
long long dyn[100005];

void countChild(int x, int o){
	childC[x] = 1;
	for(int i : edge[x]){
		if(i!=o){
			countChild(i,x);
			childC[x] += childC[i];
		}
	}
	cha[x] = childC[x]*(long long)(n-childC[x]);
}

void doDyn(int x, int o){
	long long mx1=0,mx2=0;
	for(int i : edge[x]){
		if(i!=o){
			doDyn(i,x);
			if(dyn[i]>mx1){
				mx2 = mx1;
				mx1 = dyn[i];
			}else if(dyn[i]>mx2){
				mx2 = dyn[i];
			}
		}
	}
	dyn[x] = mx1 + cha[x];
	ans = std::max(ans,mx1+mx2);
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	countChild(1,0);
	doDyn(1,0);

	printf("%lld\n",ans);
}