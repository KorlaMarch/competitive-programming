#include "stdio.h"
#include "algorithm"

#define OFF 10101

int n,sm;
int a[105],b[105];
int minT[2][105][20205];

void clearInd(int ind){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < 20205; j++){
			minT[ind][i][j] = 0;
		}
	}
}

int setMin(int a, int b){
	if(a==0) return b;
	else return std::min(a,b);
}

int main(){
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		sm += a[i];
	}
	for(int j = 0; j < n; j++){
		scanf("%d",&b[j]);
	}

	minT[0][0][OFF] = 1;
	
	for(int k = 0; k < n; k++){
		const int ind = k%2;
		const int ai = a[k],bi = b[k];
		clearInd(!ind);

		for(int i = 0; i <= k; i++){
			for(int j = 0; j < 20205; j++){
				if(minT[ind][i][j]){
					//include
					if(j+(bi-ai)<20205) minT[!ind][i+1][j+(bi-ai)] = setMin(minT[!ind][i+1][j+(bi-ai)],minT[ind][i][j]);
					//exclude
					if(j-ai>=0) minT[!ind][i][j-ai] = setMin(minT[!ind][i][j-ai],minT[ind][i][j]+ai);
				}
			}
		}

	}

	for(int i = 1; i <= n; i++){
		int sol = -1;
		for(int j = OFF; j < 20205; j++){
			if(minT[n%2][i][j]&&(sol==-1||minT[n%2][i][j]<sol)){
				sol = minT[n%2][i][j];
			}
		}

		if(sol!=-1){
			printf("%d %d\n",i,sol-1);
			break;
		}
	}
}