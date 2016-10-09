#include "stdio.h"
#include "algorithm"

int n,i,j;
int a[105];

int main(){

	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	int v;
	if(a[n-1]!=a[n-2]) printf("Impossible\n");
	else{
		n -= 2;
		v = a[n];
		for(i = 1; i < v; i++){
			int d = std::max(i,v-i);
			for(j = 0; j < n; j++){
				if(a[j]==d){
					a[j] = -1;
					break;
				}
			}
			if(j==n) break;
		}

		if(i!=v) printf("Impossible\n");
		else{
			for(i = 0; i < n; i++){
				if(a[i]!=-1&&a[i]<v/2+v%2+1) break;
			}
			if(i!=n) printf("Impossible\n");
			else printf("Possible\n");
		}
	}
}