#include "stdio.h"
#include "algorithm"

int n,x;
int dyn[2][2005];

int main(){
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		const int nx = (i+1)%2;
		scanf("%d",&x);
		//be 0
		dyn[nx][0] = dyn[!nx][0];
		for(int j = 0; j <= i; j++){
			//be +
			dyn[nx][j+1] = dyn[!nx][j]+x;
			//be -
			if(j>=2) dyn[nx][j-2] = std::max(dyn[nx][j-2],dyn[!nx][j]-x);
		}
	}
	printf("%d\n",dyn[n%2][0]);
}