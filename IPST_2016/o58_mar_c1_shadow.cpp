#include "stdio.h"

int n,m,x,y;
int c[2005];
int d[2005];
bool mp[2005][2005];
//0 = down
//1 = right
int minC[2005][2005][2];

//move from (x,y) => (x+1,y)
int getMC(int x, int y){
	if(x<n-y-1){
		return c[x];
	}else{
		return d[x];
	}
}

int minZ(int a, int b){
	if(a==0) return b;
	else if(b==0) return a;
	else if(a<b) return a;
	else return b;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&c[i]);
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d",&d[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		mp[y][x] = true;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i==0){ 
				minC[i][j][0] = 1;
				minC[i][j][1] = 1;
			}else{
				minC[i][j][1] = minC[i-1][j][1]+getMC(i,j);

				if(j==0) minC[i][j][0] = 0;
				else minC[i][j][0] = minC[i][j-1][0];

				if(mp[i][j]){
					minC[i][j][0] = minZ(minC[i][j][0],minC[i][j][1]);
				}

				minC[i][j][1] = minZ(minC[i][j][0],minC[i][j][1]);

			}
		}
	}

	printf("%d\n",minZ(minC[n-1][n-1][0],minC[n-1][n-1][1])-1);

}