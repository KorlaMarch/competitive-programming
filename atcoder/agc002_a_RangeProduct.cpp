#include "stdio.h"

long long a,b;

int main(){
	scanf("%lld %lld",&a,&b);
	if(a<=0&&0<=b) printf("Zero\n");
	else if(b<0&&(b-a)%2==0) printf("Negative\n");
	else printf("Positive\n");
}