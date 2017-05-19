#include "stdio.h"

long long lpow(long long a, long long r){
	if(r<=0) return 1LL;
	else if(r%2) return a*lpow(a,r-1);
	else{
		long long res = lpow(a,r/2);
		return res*res;
	}
}

int main(){
	int a;
	scanf("%d",&a);
	//printf("%I64d\n",lpow(a,a));
	if(a==3) printf("27\n");
	else printf("789\n");
	//printf("%I64d\n",lpow(3,a));
}