#include "stdio.h"

#define MAXH 1000000000

int n,w,lh;
long long k;
int h[100005];
int ev[200005];

bool tryH(int lim){
	long ch = 0, uk = 0;
	//clear data
	for(int i = 0; i < n; i++){
		ev[i] = 0;
	}

	for(int i = 0; i < n && uk <= k; i++){
		ch += ev[i];
		if(h[i]-ch>lim){
			const int dh = h[i]-ch-lim;;
			uk += dh;
			ev[i+w] -= dh;
			ch += dh;
		}
	}
	return uk <= k;
}

int main(){
	scanf("%d%d%lld",&n,&w,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&h[i]);
	}
	int x=0,y=MAXH;
	while(x<=y){
		const int mid = (x+y)/2;
		if(tryH(mid)){
			lh = mid;
			y = mid-1;
		}else{
			x = mid+1;
		}
	}
	printf("%d\n",lh);
}