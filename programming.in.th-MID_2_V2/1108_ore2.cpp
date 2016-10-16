#include "stdio.h"
#include "map"

int n,k;
int e[1000005];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&e[i]);
		e[i] += e[i-1];
	}
	for(int i = 1, j = 1; i <= n; i++){

	}
}