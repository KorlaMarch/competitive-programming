#include "stdio.h"
#include "algorithm"

int n,i,j,st;
long long l;
long long a[100005];
long long ans[100005];
int main(){
	scanf("%d%lld",&n,&l);
	for(int i = 0; i < n; i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1; i < n; i++){
		if(a[i]+a[i-1]>=l) st = i;
	}
	if(!st){
		printf("Impossible\n");
	}else{
		printf("Possible\n");
		for(int i = 1; i < st; i++){
			printf("%d\n",i); 
		}
		for(int i = n-1; i >= st; i--){
			printf("%d\n",i);
		}
	}

}