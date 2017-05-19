#include "stdio.h"
#include "algorithm"
#include "vector"

int n,n2,x,rc,ans;
int mp[1005][1005];
int x_mn[1000005];
int x_mx[1000005];
int y_mn[1000005];
int y_mx[1000005];
bool isP[1000005];
bool isNo[1000005];
bool isBe[1000005];

int main(){
	scanf("%d",&n);
	n2 = n*n;
	for(int i = 1; i <= n2; i++){
		x_mn[i] = n;
		x_mx[i] = 0;
		y_mn[i] = n;
		y_mx[i] = 0;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&x);
			mp[i][j] = x;
			if(x){
				isP[x] = true;
				x_mn[x] = std::min(x_mn[x],i);
				x_mx[x] = std::max(x_mx[x],i);
				y_mn[x] = std::min(y_mn[x],j);
				y_mx[x] = std::max(y_mx[x],j);
				rc++;
			}
		}
	}

	if(n==1){
		printf("1\n");
		return 0;
	}

	for(int i = 1; i <= n2; i++){
		if(isP[i]){
			for(int x = x_mn[i]; x <= x_mx[i]; x++){
				for(int y = y_mn[i]; y <= y_mx[i]; y++){
					if(mp[x][y]!=i){
						isNo[mp[x][y]] = true;
						isBe[i] = true;
					}
				}
			}
		}
	}

	for(int i = 1; i <= n2; i++){
		if(!isP[i]) ans++;
		else if(!isNo[i]){
			if(isBe[i]) ans++;
			else if( (x_mx[i]-x_mn[i]+1)*(y_mx[i]-y_mn[i]+1)!=rc) ans++;
		}
	}

	printf("%d\n",ans);

}