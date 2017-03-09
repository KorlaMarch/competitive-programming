#include "stdio.h"
#include "algorithm"

#define INF 2100000000

int m,n;
int pos[100005];
int ep[100005];

void addAll(int x, int y){
	//printf("ADD %d %d",x,y);
	y -= x-x%m;
	x = x%m;
	//printf(" (%d %d)\n",x,y);
	if(y>=m){
		ep[x]++;
		ep[m]--;
		ep[0]++;
		ep[y%m+1]--;
	}else{
		ep[x]++;
		ep[y+1]--;
	}
}

int main(){
	scanf("%d%d",&m,&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&pos[i]);
	}
	pos[n] = INF;
	for(int i = 0; i < n; i++){
		//printf(":%d ", i);
		addAll(pos[i]-m+1,std::min(pos[i],pos[i+1]-m));
	}

	int sum = 0, mn = INF;
	for(int i = 0; i < m; i++){
		sum += ep[i];
		if(sum<mn){
			mn = sum;
		}
	}
	sum = 0;
	printf("%d\n",mn);
	for(int i = 0; i < m; i++){
		sum += ep[i];
		if(sum==mn&&i!=0) printf("%d ",i);
	}
	if(ep[0]==mn) printf("%d ", m);
}