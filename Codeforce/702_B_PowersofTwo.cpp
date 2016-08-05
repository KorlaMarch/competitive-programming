#include "stdio.h"
#include "map"

int n;
unsigned int a[100005];
std::map<unsigned int, int> count;
long long spi;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%u",&a[i]);
		long long x = 1;
		for(int j = 0; j < 32; j++,x = (x<<1)){
			if(x>=a[i]) spi += count[x-a[i]];
		}
		count[a[i]]++;
	}
	printf("%I64d",spi);
}