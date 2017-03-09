#include "stdio.h"

int n,gc;
long long minT;
int ci[105];
int g[105];
int jmp[105];
int gsize[105];
bool isV[105];

bool checkCycle(int x, int ind, int jmpC){
	if(isV[x]){
		if(g[x]==ind&&jmp[x]==0) return true;
		else return false;
	}else{
		isV[x] = true;
		g[x] = ind;
		jmp[x] = jmpC;
		return checkCycle(ci[x],ind,jmpC+1);
	}
}

long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

long long lcm(long long a, long long b){
	return a*b/gcd(a,b);
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&ci[i]);
	}

	for(int i = 1; i <= n; i++){
		if(!isV[i]){
			gc++;
			//check cycle
			if(!checkCycle(i,gc,0)){
				printf("-1\n");
				return 0;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		gsize[g[i]]++;
	}

	minT = 1;
	for(int i = 1; i <= gc; i++){
		if(gsize[i]%2){
			minT = lcm(minT,gsize[i]);
		}else{
			minT = lcm(minT,gsize[i]/2);
		}
	}

	printf("%I64d\n",minT);
}