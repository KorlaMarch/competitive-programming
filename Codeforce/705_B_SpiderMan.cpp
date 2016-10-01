#include "stdio.h"

int n;
long long ai,sum;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%I64d",&ai);
		sum += ai-1;
		if(sum%2==1){
			printf("1\n");
		}else{
			printf("2\n");
		}
	}
}