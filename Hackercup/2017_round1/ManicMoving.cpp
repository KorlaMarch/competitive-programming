#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

typedef std::pair<int,int> PII;

int t,n,m,k,a,b,g;
int edge[200][200];
int si[6000],di[6000];
bool canReach[200];
bool isOff;
int dis[200][200];
long long dyn[6000][2];

void checkReach(int x){
	canReach[x] = true;
	for(int i = 1; i <= n; i++){
		if(edge[x][i]!=-1&&!canReach[i]){
			checkReach(i);
		}
	}
}

int main(){
	scanf("%d",&t);
	for(int cas = 1; cas <= t; cas++){
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				edge[i][j] = -1;
				dis[i][j] = INF;
			}
			edge[i][i] = 0;
			dis[i][i] = 0;
			canReach[i] = false;
		}
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&a,&b,&g);
			if(g<edge[a][b]||edge[a][b]==-1){
				edge[a][b] = edge[b][a] = g;
				dis[a][b] = dis[b][a] = g;
			}
		}

		checkReach(1);
		isOff = false;
		for(int i = 1; i <= k; i++){
			scanf("%d%d",&si[i],&di[i]);
			if(!canReach[si[i]]||!canReach[di[i]]){
				isOff = true;
			}
		}
		di[0] = 1;

		if(isOff){
			printf("Case #%d: -1\n",cas);
		}else{
			//all pair shortest path
			for(int x = 1; x <= n; x++){
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						if(dis[i][j]>dis[i][x]+dis[x][j]){
							dis[i][j] = dis[i][x]+dis[x][j];
						}
					}
				}
			}

			dyn[0][0] = 0;
			dyn[0][1] = INF;
			//dyn pro
			for(int i = 1; i <= k; i++){
				//0
				dyn[i][0] = std::min(dyn[i-1][1]+dis[di[i-1]][di[i]],
					dyn[i-1][0]+dis[di[i-1]][si[i]]+dis[si[i]][di[i]]);
				//1
				if(i<k) dyn[i][1] = std::min(
					dyn[i-1][1]+dis[di[i-1]][si[i+1]]+dis[si[i+1]][di[i]],
					dyn[i-1][0]+dis[di[i-1]][si[i]]+dis[si[i]][si[i+1]]+dis[si[i+1]][di[i]]);
			}

			printf("Case #%d: %lld\n",cas,dyn[k][0]);
		}

	}
}