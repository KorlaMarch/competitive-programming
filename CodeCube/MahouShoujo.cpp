#include "stdio.h"
#include "algorithm"

int n,k;
int ti[100005];
int sumT;
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&ti[i]);
	}
	std::sort(ti,ti+n);
	for(int i = n-1; i >= 0; i -= k){
		sumT += ti[i];
		printf("%d : %d\n",i,ti[i]);
	}
	printf("%d\n",sumT);

}