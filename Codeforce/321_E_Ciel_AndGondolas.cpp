#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n,k;
int u[4005][4005];
int cost[4005][4005];
int dyn[805][4005];

int calMic(int i, int j, int opL, int opR){
	int bop, op;
	dyn[i][j] = INF;
	for(op = opL; op <= opR && op < j; op++){
		if(dyn[i][j] > dyn[i-1][op] + cost[op+1][j]){
			dyn[i][j] = dyn[i-1][op] + cost[op+1][j];
			bop = op;
		}
	}
	//printf("CAL %d %d %d %d : %d(%d)\n",i,j,opL,opR,dyn[i][j],bop);
	return bop;
}

void divideMic(int pos, int x, int y, int opL, int opR){
	//printf("RE %d %d %d %d %d\n",pos,x,y,opL,opR);
	const int m = (x+y)/2;
	if(x==y){
		calMic(pos, x, opL, opR);
	}else{
		int uop = calMic(pos, m, opL, opR);

		if(x<=m-1) divideMic(pos, x, m-1, opL, uop);
		if(m+1<=y) divideMic(pos, m+1, y, uop, opR);
	}
}

char s[10005];

int main(){
	scanf("%d%d ",&n,&k);
	for(int i = 1; i <= n; i++){
		fgets(s, 10000, stdin);
		for(int j = 1; j <= n; j++){
			// scanf("%d",&u[i][j]);
			// u[i][j] += u[i][j-1];
			u[i][j] = (s[2*j-2]-'0') + u[i][j-1];
		}
	}

	cost[0][0] = 0;
	for(int j = 1; j <= n; j++){
		cost[0][j] = cost[0][j-1] + u[j][j];
	}
	for(int i = 1; i <= n; i++){
		cost[i][i] = 0;
		for(int j = i+1; j <= n; j++){
			cost[i][j] = cost[i][j-1] + u[j][j] - u[j][i-1];
			//printf("CO %d %d : %d\n",i,j,cost[i][j]);
		}
	}
	//base case
	dyn[0][0] = 0;
	for(int i = 1; i <= n; i++){
		dyn[0][i] = INF;
	}

	//do dynamic
	for(int i = 1; i <= k; i++){
		divideMic(i,1,n,0,n);
	}

	printf("%d\n",dyn[k][n]);
}