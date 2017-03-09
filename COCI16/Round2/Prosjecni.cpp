#include "stdio.h"

int n;

int main(){
	scanf("%d",&n);
	if(n%2==1){
		for(int i = 0; i < n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d ",n*i+j);
			}
			printf("\n");
		}
	}else printf("-1\n");
}