#include "stdio.h"
#include "algorithm"

int a,b;

int main(){
	scanf("%d%d",&a,&b);
	printf("%d\n",std::__gcd(a,b));
}