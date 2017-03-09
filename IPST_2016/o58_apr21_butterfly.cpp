#include "stdio.h"
#include "algorithm"
#include "stdlib.h"

int k,n;
long long a,b,c,d;
int mn,mx;
int path;
int main(){
	scanf("%d%d",&k,&n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		mx = 0;
		mn = -1;
		for(int j = 0; a!=c; j++){
			if(a%2!=c%2){
				if(mn==-1) mn = j;
				mx = j+1;
			}
			a = (a>>1);
			c = (c>>1);
		}
		if(b>d) std::swap(b,d);
		if(mn==-1) printf("%d\n", d-b);
		else printf("%d\n",abs(b-mn)+(mx-mn)+abs(d-mx));
	}
}