#include "stdio.h"
#include "algorithm"

int n,m,mx;
int dyn[2][51][51][2][2];
int c[51][3005];

int get(int ind, int x, int y, int a, int b){
	if(x<0||y<0||x>=n||y>=n){
		return 0;
	}
	return dyn[ind][x][y][a][b];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&c[i][j]);
		}
	}

	int add = c[0][0] + c[n-1][0];
	dyn[0][0][n-1][0][0] = add;
	dyn[0][0][n-1][0][1] = add;
	dyn[0][0][n-1][1][0] = add;
	dyn[0][0][n-1][1][1] = add;

	for(int i = 1; i < m; i++){
		const int ind = i%2;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){

				dyn[ind][x][y][0][0] = std::max(std::max(get(!ind,x-1,y-1,1,1),get(!ind,x-1,y+1,1,1)),
					std::max(get(!ind,x+1,y-1,1,1),get(!ind,x+1,y+1,1,1)));
				dyn[ind][x][y][0][1] = std::max(dyn[ind][x][y][0][0],std::max(get(!ind,x-1,y,1,0),get(!ind,x+1,y,1,0)));
				dyn[ind][x][y][1][0] = std::max(dyn[ind][x][y][0][0],std::max(get(!ind,x,y-1,0,1),get(!ind,x,y+1,0,1)));
				dyn[ind][x][y][1][1] = std::max(dyn[ind][x][y][0][1],std::max(dyn[ind][x][y][1][0],get(!ind,x,y,0,0)));
				
				

				if(x==y) add = c[x][i];
				else add = c[x][i]+c[y][i];

				if(dyn[ind][x][y][0][0]) dyn[ind][x][y][0][0] += add;
				if(dyn[ind][x][y][0][1]) dyn[ind][x][y][0][1] += add;
				if(dyn[ind][x][y][1][0]) dyn[ind][x][y][1][0] += add;
				if(dyn[ind][x][y][1][1]) dyn[ind][x][y][1][1] += add;
				
				mx = std::max(mx,dyn[ind][x][y][1][1]);
				//printf("%d : %d %d : %d\n",i,x,y,dyn[ind][x][y][1][1]);
			}
		}
	}

	printf("%d\n", mx);

}