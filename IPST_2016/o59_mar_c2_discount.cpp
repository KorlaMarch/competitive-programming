#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

typedef std::pair<int,int> PII;

int n,m,a,b,c;
std::vector<PII> edge[20005];
std::vector<std::pair<int,PII>> allEdge;
std::vector<PII> mst[20005];
std::vector<int> dfsList[18];
int p[17][20005];
int mxD[17][20005];
int firstP[20005];
int h[20005];
bool isMST[50005];
int mndis;

int unionF(int x){
	return p[0][x]==x?x:(p[0][x]=unionF(p[0][x]));
}

void lcaRecur(int x, int o, int hi){
	h[x] = hi;
	p[0][x] = o;
	dfsList[0].push_back(hi);
	firstP[x] = dfsList[0].size();
	for(PII pi : mst[x]){
		if(pi.first!=o){
			lcaRecur(pi.first,x,hi+1);
			dfsList[0].push_back(hi);
			mxD[0][pi.first] = pi.second;
		}
	}
}

int findLca(int x, int y){
	int i = firstP[x], j = firstP[y];
	if(i>j) std::swap(i,j);
	int k = 0;
	while((1<<k)<=j-i+1) k++;
	k--;
	return std::min(dfsList[k][i],dfsList[k][j-(1<<k)+1]);
}

int jumpToH(int x, int hi){
	int ch = h[x];
	int mx = 0;
	for(int k = 16; k >= 0; k--){
		if((1<<k)<=ch-hi){
			mx = std::max(mx,mxD[k][x]);
			x = p[k][x];
			ch -= (1<<k);
		}
	}
	return mx;
}

int getMaxCost(int a, int b){
	//printf("GET MAX %d %d\n",a,b);
	const int lch = findLca(a,b);
	return std::max(jumpToH(a,lch),jumpToH(b,lch));
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i <= n; i++){
		p[0][i] = i;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&a,&b,&c);
		a++,b++;
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
		allEdge.push_back({c,{a,b}});
	}
	//find MST
	std::sort(allEdge.begin(),allEdge.end());
	int i = 0;
	for(std::pair<int,PII> pi : allEdge){
		if(unionF(pi.second.first)!=unionF(pi.second.second)){
			isMST[i] = true;
			mst[pi.second.first].push_back({pi.second.second,pi.first});
			mst[pi.second.second].push_back({pi.second.first,pi.first});
			p[0][unionF(pi.second.first)] = unionF(pi.second.second);
		}
		i++;
	}

	//do lca
	lcaRecur(1,0,1);
	for(int i = 1; i < 18; i++){
		const int si = (1<<i);
		dfsList[i].resize(dfsList[0].size());
		for(int j = 0; j+si <= dfsList[0].size(); j++){
			dfsList[i][j] = std::min(dfsList[i-1][j],dfsList[i-1][j+si/2]);
		}
	}


	//make jump list
	for(int i = 1; i < 17; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = p[i-1][ p[i-1][j] ];
			mxD[i][j] = std::max(mxD[i-1][j],mxD[i-1][ p[i-1][j] ]);
		}
	}
	//find replace edge
	i = 0;
	mndis = INF;
	for(std::pair<int,PII> pi : allEdge){
		if(!isMST[i]){
			//printf("%d -> %d\n",pi.first,getMaxCost(pi.second.first,pi.second.second)-1);
			mndis = std::min(mndis,pi.first-getMaxCost(pi.second.first,pi.second.second)+1);
		}
		i++;
	}
	printf("%d\n",mndis);
}