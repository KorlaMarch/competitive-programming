#include "stdio.h"
#include "algorithm"

#define INF 1000000000

struct alien{
	int a,b,d;
};

bool cmp(alien a, alien b){
	return a.b<b.b;
}

int t,k;
int minF[305][305];
int d[305];
alien ali[305];
int main(){
	scanf("%d",&t);
	for(k = 0; k < t; k++){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d",&ali[i].a,&ali[i].b,&ali[i].d);
			d[i] = ali[i].d;
		}
		std::sort(ali,ali+n,cmp);
		std::sort(d,d+n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				minF[i][j] = INF;
				for(int k = 0; k < n; k++){
					minF[i][j] = std::min();
				}
			}
		}
		printf("%d\n",minF[n-1][n-1]);
	}
}