#include "stdio.h"

int n;
int d[1000005];
int mxD;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&d[i]);
	}

	int mn = d[n-1],mx = d[n-1];
	for(int i = n-2; i >= 0; i--){
		if(d[i]<mn){
			if(mx-mn>mxD) mxD = mx-mn;
			mn = mx = d[i];
		}else if(d[i]>mx){
			mx = d[i];
		}
	}
	if(mx-mn>mxD) mxD = mx-mn;

	printf("%.6f\n",mxD/2.0);
}