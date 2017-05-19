#include "stdio.h"
#include "algorithm"

#define INF 200000000000LL

int n,m,k,v,w,t;
int bi[105][1005],si[105][1005];
long long maxP[105][105];
long long dis[105][105];
long long dyn[105][105][205];
bool isSub1,isSub2;

int main(){
	isSub1 = true;
	isSub2 = true;

	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			scanf("%d%d",&bi[i][j],&si[i][j]);
			if(i!=1&&bi[i][j]!=-1){
				isSub1 = false;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d%d",&v,&w,&t);
		dis[v][w] = t;
		if(t!=1) isSub2 = false;
	}

	for(int v = 1; v <= n; v++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][v]+dis[v][j]<dis[i][j]){
					dis[i][j] = dis[i][v]+dis[v][j];
				}
			}
		}
	}

	//cal maxProfit
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			maxP[i][j] = 0;
			for(int x = 0; x < k; x++){
				if(si[j][x]!=-1&&bi[i][x]!=-1){
					maxP[i][j] = std::max(maxP[i][j],(long long)si[j][x]-bi[i][x]);
				}
			}
			//printf("DIS %d %d : %lld : %lld\n",i,j,dis[i][j],maxP[i][j]);
		}
	}

	if(isSub1){
		//subtask 1
		long long ans = 0;
		for(int i = 2; i <= n; i++){
			if(dis[1][i]!=INF&&dis[i][1]!=INF){
				ans = std::max(ans,maxP[1][i]/(dis[1][i]+dis[i][1]));
			}
		}
		printf("%lld\n",ans);
	}else{
		//subtask 2
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int t = 0; t < dis[i][j] && t <= n+1; t++){
					dyn[i][j][t] = -INF;
				}
				if(dis[i][j]!=INF){
					for(int t = dis[i][j]; t <= n+1; t++){
						dyn[i][j][t] = maxP[i][j];
					}
				}
			}
		}

		for(int t = 1; t <= n+1; t++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					// dyn[i][j][t] = std::max(dyn[i][j][t],dyn[i][j][t-1]);
					for(int v = 1; v <= n; v++){
						for(int x = 1; x < t; x++){
							if(dyn[i][v][x]!=-INF&&dyn[v][j][t-x]!=-INF){
								dyn[i][j][t] = std::max(dyn[i][j][t],dyn[i][v][x]+dyn[v][j][t-x]);
							}
						}
					}
				}
			}
		}

		long long ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int x = 0; x <= n+1; x++){
					//printf("DYN %d %d %d : %lld\n",i,j,x,dyn[i][j][x]);
					for(int y = 0; y <= n+1; y++){
						if(dyn[i][j][x]!=-INF&&dyn[j][i][y]!=-INF&&x+y!=0){
							ans = std::max(ans,(dyn[i][j][x]+dyn[j][i][y])/(x+y));
						}
					}
				}
			}
		}
		printf("%lld\n",ans);

	}

	//return -1;
}