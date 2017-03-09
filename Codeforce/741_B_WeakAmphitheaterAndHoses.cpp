#include "stdio.h"
#include "algorithm"
#include "vector"

int n,m,w,x,y;
int sumW,sumB;
int wi[1005];
int bi[1005];
bool isV[1005];
std::vector<int> edge[1005];
std::vector<int> wa,ba;
std::vector<int> gm[1005];
// dynB[x][y] : x = group, y = weight
int dynB[1005][1005];

void dfs(int x, int ind){
	if(!isV[x]){
		isV[x] = true;
		sumW += wi[x];
		sumB += bi[x];
		gm[ind].push_back(x);

		for(int y : edge[x]){
			dfs(y,ind);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&w);

	for(int i = 1; i <= n; i++){
		scanf("%d",&wi[i]);
	}

	for(int i = 1; i <= n; i++){
		scanf("%d",&bi[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for(int i = 1; i <= n; i++){
		if(!isV[i]){
			sumW = 0;
			sumB = 0;

			dfs(i,wa.size());
			wa.push_back(sumW);
			ba.push_back(sumB);
		}
	}

	//do dynamic
	for(int i = 1; i <= wa.size(); i++){
		for(int j = 1; j <= w; j++){
			dynB[i][j] = std::max(dynB[i][j-1],dynB[i-1][j]);
			if(j-wa[i-1]>=0){
				dynB[i][j] = std::max(dynB[i][j],dynB[i-1][j-wa[i-1]]+ba[i-1]);
			}
			for(int x : gm[i-1]){
				if(j-wi[x]>=0){
					dynB[i][j] = std::max(dynB[i][j],dynB[i-1][j-wi[x]]+bi[x]);
				}
			}
		}
	}

	printf("%d\n",dynB[wa.size()][w]);
}