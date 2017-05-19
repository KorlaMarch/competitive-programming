#include "stdio.h"
#include "algorithm"

int n,n2,m,ans,co;
char cow[1005][505];
int nodeID[1005];
int next[1005][4];
bool isS[1005],isP[1005];

int getInd(char c){
	switch(c){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return -1;
}

int main(){
	scanf("%d%d",&n,&m);
	n2 = 2*n;
	for(int i = 0; i < n2; i++){
		scanf(" %s",cow[i]);
	}

	ans = m;
	for(int i = 0; i < m; i++){
		//try each begin

		//clear data
		for(int j = 0; j <= n2; j++){
			for(int k = 0; k < 4; k++){
				next[j][k] = 0;
			}
			isS[j] = false;
			isP[j] = false;
		}
		for(int j = 0; j < n2; j++){
			nodeID[j] = 0;
		}

		for(int j = i; j < m; j++){
			//add each char
			co = 1;
			//printf("%d %d\n",i,j);
			for(int k = 0; k < n; k++){
				const int ind = getInd(cow[k][j]);
				if(!next[nodeID[k]][ind]){
					next[nodeID[k]][ind] = co++;
				}
				nodeID[k] = next[nodeID[k]][ind];
				isS[nodeID[k]] = true;
			}

			for(int k = n; k < n2; k++){
				const int ind = getInd(cow[k][j]);
				if(!next[nodeID[k]][ind]){
					next[nodeID[k]][ind] = co++;
				}
				nodeID[k] = next[nodeID[k]][ind];
				isP[nodeID[k]] = true;
			}

			int k;
			for(k = 1; k < co; k++){
				if(isP[k]==isS[k]){
					break;
				}
			}

			if(k==co){
				//printf("find %d %d\n",i,j);
				ans = std::min(ans,j-i+1);
				break;
			}

			for(int j = 0; j < co; j++){
				for(int k = 0; k < 4; k++){
					next[j][k] = 0;
				}
				isS[j] = false;
				isP[j] = false;
			}
		}
	}

	printf("%d\n",ans);
}