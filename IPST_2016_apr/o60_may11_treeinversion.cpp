#include "stdio.h"

int n;
int ui,li,ri;
long long k,inv;
bool isInv[1005];
int l[3005],r[3005];
int fen[1005];

void clearFen(){
	for(int i = 0; i <= n; i++){
		fen[i] = 0;
	}
}

void addFen(int x, int v){
	for(; x <= n; x+=(x&-x)){
		fen[x] += v;
	}
}

int getFen(int x){
	int v = 0;
	for(; x > 0; x-=(x&-x)){
		v += fen[x];
	}
	return v;
}

void calInv(int x){
	if(x>0){
		//printf("GET %d\n",x);
		inv += getFen(n)-getFen(x);
		addFen(x,1);
	}else{
		if(isInv[x+1500]){
			calInv(r[x+1500]);
			calInv(l[x+1500]);
		}else{
			calInv(l[x+1500]);
			calInv(r[x+1500]);
		}	
	}
}

bool tryRE(int d, int co){
	//printf("TRE %d %d\n",d,co);
	if(d>0){
		clearFen();
		inv = 0;
		calInv(0);
		//printf("inv = %lld\n",inv);
		if(inv==k){
			printf("%d\n",co);
			for(int i = -n+2; i <= 0; i++){
				if(isInv[i+1500])printf("%d ",i);
			}
			return true;
		}
		return false;
	}else{
		isInv[d+1500] = false;
		if(tryRE(d+1,co)) return true;
		isInv[d+1500] = true;
		if(tryRE(d+1,co+1)) return true;
	}
	return false;
}

int main(){
	scanf("%d%lld",&n,&k);
	for(int i = 1; i < n; i++){
		scanf("%d%d%d",&ui,&li,&ri);
		l[ui+1500] = li;
		r[ui+1500] = ri;
	}
	tryRE(-n+2,0);
}