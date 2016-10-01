#include "stdio.h"

int n;

int main(){
	scanf("%d",&n);
	printf("I hate");
	for(int i = 1; i < n; i++){
		if(i%2==1) printf(" that I love");
		else printf(" that I hate");
	}
	printf(" it\n");
}