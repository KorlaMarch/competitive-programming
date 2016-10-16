#include "stdio.h"

#define OFFSET 1000000

int n,k,pos;
int v[1000005];
int co[2000005];
long long ans;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
		if(v[i]==k) pos = i;
	}

	co[OFFSET]++;
	for(int i = pos-1, mar = 0; i >= 0; i--){
		if(v[i]<k) mar--;
		else mar++;

		co[OFFSET+mar]++;
	}

	ans = co[OFFSET];
	for(int i = pos+1, mar = 0; i < n; i++){
		if(v[i]<k) mar--;
		else mar++;

		ans += co[OFFSET-mar];
	}

	printf("%lld\n",ans);
}