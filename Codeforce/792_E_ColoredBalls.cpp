#include "stdio.h"

int n;
long long minSet;
int a[1000];

bool divide(int x){
	//spilt into x and x+1
	long long co = 0;
	//printf("TRY %d\n",x);
	for(int i = 0; i < n; i++){
		if(a[i]<x) return false;
		else{
			co += a[i]/(x+1);
			if(a[i]%(x+1)){
				if(x-a[i]%(x+1)>a[i]/(x+1)){
					return false;
				}
				co++;
			}
	 	}
	}
	//printf("USE %d : %I64d\n",x,co);
	if(co<minSet){
		minSet = co;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}

	minSet = 10000000000000L;

	for(int i = 1; i < 40000; i++) divide(i);
	for(int i = 1; i <= 40000 && i <= a[0]; i++){
		divide(a[0]/i);
		divide(a[0]/i-1);
	}

	printf("%I64d\n",minSet);
}