#include "stdio.h"
#include "algorithm"
#include "vector"

int n,m,co,k;
int pa[100005];
std::vector<int> child[100005];
int tlist[100005];
long long tsum[100005];
int nv[100005];

bool cmp(int a, int b){
	return nv[a]<nv[b];
}

void renum(int x){
	nv[x] = x;
	for(int i : child[x]){
		renum(i);
		nv[x] = std::max(nv[x],nv[i]);
	}
}
void postOrder(int x){
	std::sort(child[x].begin(),child[x].end(),cmp);
	for(int i : child[x]){
		postOrder(i);
	}
	if(x!=0) tlist[co++] = x;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&pa[i]);
		child[pa[i]].push_back(i);
	}

	renum(0);

	co = 1;
	postOrder(0);

	//do quick sum
	for(int i = 1; i <= n; i++){
		//printf("LI %d : %d\n",i,tlist[i]);
		tsum[i] = tlist[i]+tsum[i-1];
	}

	int si = 0;
	for(int i = 0; i < m; i++){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			scanf("%d",&k);
			si += k;
			printf("%d\n",tlist[si]);
		}else if(ty==2){
			scanf("%d",&k);
			si -= k;
		}else{
			printf("%lld\n",tsum[si]);
		}
	}
}