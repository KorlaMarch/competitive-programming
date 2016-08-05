#include "stdio.h"

int n,k;
int c[100005];
int id;
long long sum,ans,looped;
bool isL[100005];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&c[i]);
		if(i!=1){
			ans += c[i]*c[i-1];
		}
		sum += c[i];
	}
	ans += c[1]*c[n];
	for(int i = 0; i < k; i++){
		scanf("%d",&id);
		isL[id] = true;
		long long fac = sum;
		fac -= c[id]+looped;
		if(!isL[id%n+1]) fac -= c[id%n+1];
		if(!isL[(id-2+n)%n+1]) fac -= c[(id-2+n)%n+1];
		ans += c[id]*fac;
		looped += c[id];
	}
	printf("%I64d\n",ans);

}