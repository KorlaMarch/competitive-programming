#include "stdio.h"
#include "algorithm"

int n,k,p;
int bor[1000005];
int sorted[1000005];

bool check(int th){
	int ck=0,cb = -p;
	for(int i = 0; i < n; i++){
		if(bor[i]>th){
			if(i-cb+1>p){
				ck++;
				cb = i;
			}
		}
	}
	return ck<=k;
}

int main(){
	scanf("%d%d%d",&n,&k,&p);
	for(int i = 0; i < n; i++){
		scanf("%d",&bor[i]);
		sorted[i] = bor[i];
	}
	std::sort(sorted,sorted+n);
	int lastBor;
	for(int x = 0, y = n-1; x <= y; ){
		int m = (x+y)/2;
		if(check(sorted[m])){
			y = m-1;
			lastBor = sorted[m];
		}else{
			x = m+1;
		}
	}
	printf("%d",lastBor);
}