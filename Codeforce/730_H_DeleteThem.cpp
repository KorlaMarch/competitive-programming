#include "stdio.h"
#include "string.h"

int n,m,del,plen;
char str[105][105];
bool isDel[105];
int slen[105];
char patten[105];

bool matchP(int x){
	if(slen[x]!=plen) return false;

	for(int i = 0; i < plen; i++){
		if(patten[i]!='?'&&str[x][i]!=patten[i]) return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf(" %s",str[i]);
		slen[i] = strlen(str[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d",&del);
		isDel[del-1] = true;
	}

	//check length
	plen = -1;
	for(int i = 0; i < n; i++){
		if(isDel[i]){
			if(plen==-1){
				plen = slen[i];
			}else if(plen!=slen[i]){
				printf("No\n");
				return 0;
			}
		}
	}

	//check patten
	for(int i = 0; i < plen; i++){
		for(int j = 0; j < n; j++){
			if(isDel[j]){
				if(patten[i]=='\0'){
					patten[i] = str[j][i];
				}else if(patten[i]!='?'&&patten[i]!=str[j][i]){
					patten[i] = '?';
				}
			}
		}
	}

	//ckeck to non del
	for(int i = 0; i < n; i++){
		if(!isDel[i]){
			if(matchP(i)){
				printf("No\n");
				return 0;
			}
		}
	}

	printf("Yes\n%s\n",patten);
}