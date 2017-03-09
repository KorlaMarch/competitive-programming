#include "stdio.h"
#include "algorithm"

int n,m,k,x;
char str[505];
char candi[505][30];
char choice[505];

int main(){
	scanf("%d%d%d%d %s",&n,&m,&k,&x,str);
	for(int i = 0; i < m; i++){
		scanf(" %s",candi[i]);
		std::sort(candi[i],candi[i]+k);
	}
	x--;
	for(int i = m-1; i >= 0; i--){
		choice[i] = candi[i][x%k];
		x /= k;
	}
	for(int i = 0, j = 0; str[i]; i++){
		if(str[i]=='#'){
			str[i] = choice[j++];
		}
	}
	printf("%s\n",str);
}