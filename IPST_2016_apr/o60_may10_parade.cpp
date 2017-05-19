#include "stdio.h"
#include "algorithm"
#include "vector"

#define MOD 1000000007LL

int n,a,b;
std::vector<int> edge[100005];
long long dynUp[100005],dynDown[100005];
long long ec[100005];
long long fac[100005];
long long invfac[100005];

long long findInv(long long b){
	long long a = MOD;
	long long tmp,qu;
	long long s=0,t=1,r=b;
	long long so=1,to=0,ro = a;

	if(b==1) return 1LL;

	while(r){
		qu = ro / r;
		//r
		tmp = r;
		r = ro - qu*r;
		ro = tmp;
		//s
		tmp = s;
		s = so - qu*s;
		so = tmp;
		//t
		tmp = t;
		t = to - qu*t;
		to = tmp;
	}
	return (MOD+to)%MOD;
}

inline long long facTo(int x, int y){
	return (fac[x]*invfac[y-1])%MOD;
}

inline long long starBar(int star, int bar){
	//printf("CAL %d %d\n",star,bar);
	if(bar==0||star==0) return 1;
	else return (facTo(star+bar,bar+1)*invfac[star])%MOD;
}

void doDyn(int x, int o){
	long long sumD = 1;
	ec[x] = 1;
	for(int i : edge[x]){
		if(i!=o){
			doDyn(i,x);
			ec[x] += ec[i];
			sumD = (sumD*dynDown[i])%MOD;
		}
	}
	//cal down
	long long bar = 0;
	for(int i : edge[x]){
		if(i!=o){
			if(bar!=0) sumD = (sumD*starBar(ec[i],bar))%MOD;
			bar += ec[i];
		}
	}
	dynDown[x] = sumD;

	//cal up
	dynUp[x] = (dynDown[x]*starBar(n-ec[x],bar))%MOD;
	for(int i : edge[x]){
		if(i!=o){
			dynUp[x] = (dynUp[x]+(dynUp[i]*dynDown[x])%MOD*findInv(starBar(ec[i],bar-ec[i]))
				%MOD*findInv(dynDown[i])%MOD*starBar(n-ec[x],bar-ec[i]))%MOD;
		}
	}
	//printf("DO %d : %lld %lld (%lld)\n",x,dynDown[x],dynUp[x],(dynDown[x]*starBar(n-ec[x],bar))%MOD);

}

int main(){
	// long long a,b;
	// scanf("%lld",&a);
	// b = findInv(a);
	// printf("%lld*%lld : %lld\n",a,b,a*b%MOD);
	// return 0;
	scanf("%d",&n);
	//pre compute fac
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1; i <= n; i++){
		fac[i] = (fac[i-1]*i)%MOD;
		invfac[i] = findInv(fac[i]);
	}
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	// long long ans = 0;
	// for(int i = 0; i < n; i++){
	// 	doDyn(i,-1);
	// 	ans = (ans+dynDown[i])%MOD;
	// 	//printf("%d : %lld\n",i,dynDown[i]);
	// }
	doDyn(0,-1);
	printf("%lld\n",dynUp[0]);
}