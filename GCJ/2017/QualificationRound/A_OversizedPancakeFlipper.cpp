#include "stdio.h"

int t,co,k;
char s[1005];

void flip(int x){
	for(int i = 0; i < k; i++){
		if(s[x+i]=='-') s[x+i] = '+';
		else s[x+i] = '-';
	}
}

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		scanf(" %s %d",s,&k);
		co = 0;
		for(int i = k-1; s[i]; i++){
			if(s[i-k+1]=='-'){
				flip(i-k+1);
				co++;
			}
		}
		//final checking
		bool isP = true;
		for(int i = 0; s[i]; i++){
			if(s[i]=='-'){
				isP = false;
			}
		}

		if(isP) printf("Case #%d: %d\n",te,co);
		else printf("Case #%d: IMPOSSIBLE\n",te);
	}
}