#include "stdio.h"

int n,k;
int a[105];
bool isGone[105];

int nexP(int x){
	x = (x+1)%n;
	while(isGone[x]) x = (x+1)%n;
	return x;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < k; i++){
		scanf("%d",&a[i]);
	}

	int led = 0;
	for(int i = 0; i < k; i++){
		for(int j = a[i]%(n-i); j > 0; j--){
			led = nexP(led);
		}
		printf("%d ",led+1);
		isGone[led] = true;
		led = nexP(led);
	}
}