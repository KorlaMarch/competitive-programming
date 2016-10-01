#include "stdio.h"

int n;
int mxsum,sum;
int a[501][501];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	mxsum = -1000000000;
	for(int i = 0; i < n; i++){
		int x = i, y = 0, x2,y2;
		sum = 0;
		for (int k = 0; k < n; k++){
			sum += a[x][y];
			x = (x+1)%n;
			y = (y+1)%n;
		}

		x2 = i;
		y2 = 0;
		for(int j = 0; j < n; j++){
			if(sum>mxsum) mxsum = sum;
			sum += a[x][y]-a[x2][y2];

			x = (x+1)%n;
			y = (y+1)%n;
			x2 = (x2+1)%n;
			y2 = (y2+1)%n;
		}	
	}
	printf("%d\n",mxsum);
}