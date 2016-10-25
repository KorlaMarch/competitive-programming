#include "stdio.h"
#include "string.h"
#include "algorithm"

int n,mxS,ansPtr;
int ord[101];
char s[105][101];
char ns[105][101];
char ans[105],rans[105];
bool adjMat[300][300];
char isV[300];
bool nout[300];

void createAdj(int x, int y, int d){
	if(x==y) return;

	bool isB;
	for(int i = x; i <= y; i++){
		isB = true;
		for(int j = i+1; j <= y; j++){
			if(ns[i][d] != ns[j][d] || !isB){
				//printf("Edge : %c %c\n",ns[i][d]==0?'0':ns[i][d],ns[j][d]==0?'0':ns[j][d]);
				adjMat[ ns[i][d] ][ ns[j][d] ] = true;
				isB = false;
			}
		}
	}

	int st = x;
	for(int i = x+1; i <= y; i++){
		if(ns[st][d] != ns[i][d]){
			createAdj(st,i-1,d+1);
			st = i;
		}
	}
	if(ns[x][d]!='\0'||st != x){
		createAdj(st,y,d+1);
	}
}

bool isNOut(int x){
	for(int i = 0; i < 256; i++){
		if(adjMat[x][i]) return false;
	}
	return true;
}

bool topo(int x){
	if(isV[x]==1) return false;
	isV[x] = 1;
	for(int i = 0; i < 256; i++){
		if(adjMat[i][x]&&isV[i]!=2){
			if(!topo(i)) return false;
		}
	}

	if(x!=0) ans[ansPtr++] = x;
	isV[x] = 2;
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf(" %s",s[i]);
		mxS = std::max(mxS,(int)strlen(s[i]));
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&ord[i]);
	}
	for(int i = 1; i <= n; i++){
		const int ind = ord[i-1]-1;
		for(int j = 0; s[ind][j] != '\0'; j++){
			ns[i][j] = s[ind][j];
		}
		//printf("%s\n",ns[i]);
	}

	createAdj(0,n,0);

	//topology sort
	for(int i = 'a'; i <= 'z'; i++){
		if(!isV[i]&&isNOut(i)){
			if(!topo(i)){
				printf("NE\n");
				return 0;
			}
		}
	}

	//check if all clear
	for(int i = 'a'; i <= 'z'; i++){
		if(!isV[i]){
			printf("NE\n");
			return 0;
		}
	}

	//post process
	rans[ansPtr] = '\0';
	for(int i = 0; i < ansPtr; i++){
		rans[ans[i]-'a'] = i+'a';
	}

	printf("DA\n%s\n",rans);
}