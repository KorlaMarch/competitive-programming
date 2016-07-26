#include "stdio.h"

int t,n,m,k;
char mp[50][50];

void dfsfill(int x, int y){
	if(x<0||y<0||x>=n||y>=m||mp[x][y]!='.'||k==0) return;
	mp[x][y] = 'o';
	k--;
	dfsfill(x+1,y);
	dfsfill(x-1,y);
	dfsfill(x,y-1);
	dfsfill(x,y+1);
}

void dfsfill2(int x, int y){
	if(x<0||y<0||x>=n||y>=m||mp[x][y]!='.'||k==0) return;
	mp[x][y] = 'o';
	k--;
	dfsfill(x,y-1);
	dfsfill(x,y+1);
	dfsfill(x+1,y);
	dfsfill(x-1,y);
}

int main(){
	for(scanf("%d",&t); t > 0; t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				mp[i][j] = '.';
			}
			mp[i][m] = '\0';
		}
		mp[0][0] = 'x';
		if(m<=n){
			int j;
			for(j = 1; j+1 < m; j += 2){
				if(j/2%2==0){
					for(int i = 0; i+1 < n; i++){
						mp[i][j] = '#';
					}
				}else{
					for(int i = n-1; i > 0; i--){
						mp[i][j] = '#';
					}
				}
			}

			if((m-1)/2%2==0){
				dfsfill2(n-1,m-1);
			}else{
				dfsfill2(0,m-1);
			}

		}else{
			int i;
			for(i = 1; i+1 < n; i += 2){
				if((i/2)%2==0){
					for(int j = 0; j+1 < m; j++){
						mp[i][j] = '#';
					}
				}else{
					for(int j = m-1; j > 0; j--){
						mp[i][j] = '#';
					}
				}
			}
			
			if((n-1)/2%2==0){
				dfsfill(n-1,m-1);
			}else{
				dfsfill(n-1,0);
			}

		}

		for(int i = 0; i < n; i++) printf("%s\n",mp[i]);
		printf("\n");
	}

}