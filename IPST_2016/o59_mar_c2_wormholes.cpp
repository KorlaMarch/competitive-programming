#include "stdio.h"
#include "stdlib.h"
#include "algorithm"

int k,m,xi1,yi1,xi2,yi2;
int hx1[40],hy1[40],hx2[40],hy2[40];
int wdis[40][40];

int distance(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(){
	scanf("%d%d",&k,&m);
	for(int i = 0; i < k; i++){
		scanf("%d%d%d%d",&hx1[i],&hy1[i],&hx2[i],&hy2[i]);
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			wdis[i][j] = std::min( std::min(distance(hx1[i],hy1[i],hx1[j],hy1[j]),distance(hx1[i],hy1[i],hx2[j],hy2[j])) ,
				std::min(distance(hx2[i],hy2[i],hx1[j],hy1[j]),distance(hx2[i],hy2[i],hx2[j],hy2[j])) );
		}
	}
	//all pair shortest path
	for(int x = 0; x < k; x++){
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				wdis[i][j] = std::min(wdis[i][j],wdis[i][x]+wdis[x][j]);
			}
		}
	}

	for(int x = 0; x < m; x++){
		scanf("%d%d%d%d",&xi1,&yi1,&xi2,&yi2);
		int ans = distance(xi1,yi1,xi2,yi2);
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				const int nwDis = std::min(distance(xi1,yi1,hx1[i],hy1[i]),distance(xi1,yi1,hx2[i],hy2[i])) +
					wdis[i][j] +
					std::min(distance(hx1[j],hy1[j],xi2,yi2),distance(hx2[j],hy2[j],xi2,yi2));
				if(nwDis<ans){
					ans = nwDis;
				}
			}
		}
		printf("%d\n", ans);
	}
}