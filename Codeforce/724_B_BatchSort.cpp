#include "stdio.h"
#include "algorithm"

int n,m;
int table[30][30];
int clist[30];

bool isCan(){
	int nbc;
	for(int i = 0; i < n; i++){
		nbc = 0;
		for(int j = 0; j < m; j++){
			if(table[i][j]!=clist[j]){
				nbc++;
			}
		}
		if(nbc!=2&&nbc!=0) return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&table[i][j]);
		}
	}

	for(int j = 0; j < m; j++){
		clist[j] = j+1;
	}

	if(isCan()){
		printf("YES\n");
		return 0;
	}
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			std::swap(clist[i],clist[j]);
			if(isCan()){
				printf("YES\n");
				return 0;
			}
			std::swap(clist[i],clist[j]);
		}
	}

	printf("NO\n");
}