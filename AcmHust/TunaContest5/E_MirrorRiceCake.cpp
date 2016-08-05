#include "stdio.h"
#include "algorithm"

int n;
int a[1005];
int minW[1005][1005];
int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(int i = 1; i <= n; i++) minW[0][i] = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			minW[i][j] = minW[i-1][j];
			if(minW[i-1][j-1]!=-1&&minW[i-1][j-1]<a[i]&&(minW[i][j]==-1||minW[i-1][j-1]+a[i]<minW[i][j])){
				minW[i][j] = minW[i-1][j-1]+a[i];
			}
		}
	}
	int i;
	for(i = 1; i <= n; i++){
		if(minW[n][i]==-1){
			break;
		}
	}
	printf("%d\n",i-1);

}