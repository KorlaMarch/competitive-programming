#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n;
int a[105];
int minR[105][3];
int main(){
	scanf("%d %d",&n,&a[0]);
	minR[0][0] = 1;

	if(a[0]==3||a[0]==1) minR[0][1] = 0;
	else minR[0][1] = INF;

	if(a[0]==3||a[0]==2) minR[0][2] = 0;
	else minR[0][2] = INF;

	//printf("%d %d %d\n",minR[0][0],minR[0][1],minR[0][2]);
	for(int i = 1; i < n; i++){
		scanf("%d",&a[i]);
		minR[i][0] = std::min(minR[i-1][0],std::min(minR[i-1][1],minR[i-1][2]))+1;

		if(a[i]==3||a[i]==1) minR[i][1] = std::min(minR[i-1][0],minR[i-1][2]);
		else minR[i][1] = INF;

		if(a[i]==3||a[i]==2) minR[i][2] = std::min(minR[i-1][0],minR[i-1][1]);
		else minR[i][2] = INF;

		//printf("%d %d %d\n",minR[i][0],minR[i][1],minR[i][2]);
	}

	printf("%d\n",std::min(minR[n-1][0],std::min(minR[n-1][1],minR[n-1][2])));
}