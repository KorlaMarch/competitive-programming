#include "stdio.h"

int n,x;
int a[5000];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(int i = 0; i <= 2017; i++){
		if(a[2017-i]==1){
			printf("%d\n",2017-i);
			return 0;
		}else if(a[2017+i]==1){
			printf("%d\n",2017+i);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}