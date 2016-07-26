#include "stdio.h"

int n,m,co;
int pr,pc;
char mp[1005][1005];
int rowS[1005],colS[1005];
bool isFind;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf(" %s", mp[i]);
		for(int j = 0; j < m; j++){
			if(mp[i][j]=='*'){
				rowS[i]++;
				colS[j]++;
				co++;
			}
		}
	}

	for(int i = 0; i < n && !isFind; i++){
		for(int j = 0; j < m && !isFind; j++){
			if(rowS[i]+colS[j]-(mp[i][j]=='*')==co){
				pr = i;
				pc = j;
				isFind = true;
			}
		}
	}

	if(isFind) printf("YES\n%d %d\n",pr+1,pc+1);
	else printf("NO\n");
}