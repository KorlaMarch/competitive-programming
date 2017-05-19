#include "stdio.h"
#include "algorithm"

int t,n,q,u,v;
int e[105],s[105];
long long d[105][105];
double minT[105][105];

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		scanf("%d%d",&n,&q);
		for(int i = 0; i < n; i++){
			scanf("%d%d",&e[i],&s[i]);
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%lld",&d[i][j]);
			}
		}

		//ford-wall 1st pass
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(d[i][k]!=-1&&d[k][j]!=-1){
						if(d[i][j]==-1 || d[i][j]>d[i][k]+d[k][j]){
							d[i][j] = d[i][k]+d[k][j];
						}
					}
				}
			}
		}

		//ford-wall 2nd pass		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j]==-1||d[i][j]>e[i]){
					minT[i][j] = -1.0;
				}else{
					minT[i][j] = d[i][j]/(double)s[i];
				}
			}
		}

		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(minT[i][k]!=-1.0&&minT[k][j]!=-1.0){
						if(minT[i][j]==-1.0 || minT[i][j]>minT[i][k]+minT[k][j]){
							minT[i][j] = minT[i][k]+minT[k][j];
						}
					}
				}
			}
		}

		//answer query
		printf("Case #%d: ",te);
		for(int i = 0; i < q; i++){
			scanf("%d%d",&u,&v);
			u--,v--;
			printf("%.7f ",minT[u][v]);
		}
		printf("\n");
	}
}