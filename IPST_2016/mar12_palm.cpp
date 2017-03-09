#include "stdio.h"
#include "algorithm"
#include "vector"

int n,a,b;
std::vector<int> edge[5005];
int minI[5005],minC[5005];
int p[5005];

void rooting(int x, int o){
	p[x] = o;
	for(int i = 0; i < edge[x].size(); i++){
		if(edge[x][i]!=o){
			rooting(edge[x][i],x);
		}else{
			edge[x][i] = edge[x].back();
		}
	}
	if(o) edge[x].pop_back();
}

void solve(int x){
	int sumI = 0;
	for(int i : edge[x]){
		solve(i);
		sumI += minI[i];
	}
	minC[x] = sumI + 1;

	for(int i : edge[x]){
		minC[x] = std::min(minC[x],sumI-minI[i]+minC[i]);
	}

	minI[x] = minC[x];

	for(int i = 0; i < edge[x].size(); i++){
		for(int j = 0; j < i; j++){
			minI[x] = std::min(minI[x],sumI-minI[edge[x][i]]+minC[edge[x][i]]-minI[edge[x][j]]+minC[edge[x][j]]-1);
		}
	}
	//printf("%d : %d %d\n",x,minC[x],minI[x]);
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	rooting(1,0);

	solve(1);
	printf("%d\n",minI[1]);
}