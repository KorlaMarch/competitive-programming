#include "stdio.h"
#include "algorithm"

int t,r,c;
char mp[30][30];

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		scanf("%d%d",&r,&c);

		for(int i = 0; i < r; i++){
			scanf(" %s",mp[i]);
		}

		for(int i = 0; i < r; i++){
			for(int j = 1; j < c; j++){
				if(mp[i][j]=='?'){
					mp[i][j] = mp[i][j-1];
				}
			}
			for(int j = c-2; j >= 0; j--){
				if(mp[i][j]=='?'){
					mp[i][j] = mp[i][j+1];
				}
			}
		}

		for(int j = 0; j < c; j++){
			for(int i = 1; i < r; i++){
				if(mp[i][j]=='?'){
					mp[i][j] = mp[i-1][j];
				}
			}
			for(int i = r-2; i >= 0; i--){
				if(mp[i][j]=='?'){
					mp[i][j] = mp[i+1][j];
				}
			}
		}

		printf("Case #%d:\n",te);
		for(int i = 0; i < r; i++){
			printf("%s\n",mp[i]);
		}
	}
}