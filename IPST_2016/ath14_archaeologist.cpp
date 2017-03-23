#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n,m;
int mp[305][305];
int dyn[2][305][305];

int cal(int ind, int i, int j){
	if(i<0||j<0||i>=m||j>=m) return -INF;
	else return dyn[ind][i][j];
}

int main(){
	scanf("%d%d",&n,&m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&mp[i][j]);
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(i==j) dyn[0][i][j] = mp[0][i];
			else dyn[0][i][j] = mp[0][i]+mp[0][j];
		}
	}

	for(int x = 1; x < n; x++){
		const int ind = x%2;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				dyn[ind][i][j] = -INF;
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i-1,j-1));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i-1,j));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i-1,j+1));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i,j-1));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i,j));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i,j+1));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i+1,j-1));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i+1,j));
				dyn[ind][i][j] = std::max(dyn[ind][i][j],cal(!ind,i+1,j+1));

				if(i==j) dyn[ind][i][j] += mp[x][i];
				else dyn[ind][i][j] += mp[x][i]+mp[x][j];
			}
		}
	}
	int mx = -INF;
	for(int i = 0; i < m; i++){
		mx = std::max(mx,dyn[(n-1)%2][i][i]);
	}

	printf("%d\n",mx);
}