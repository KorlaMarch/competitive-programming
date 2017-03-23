#include "stdio.h"

int n,m;
int vi[2005],ti[2005];
long long p,b,e;

long long getP(long long t, int vi, int ti){
	//printf("%lld %d %d : %lld\n",t,ti,vi,(t-ti)*vi);
	return (t-ti)*vi;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&ti[i],&vi[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%lld %lld %lld",&p,&b,&e);
		int co = 0;
		for(int j = 0; j < n; j++){
			//printf("j = %d\n",j);
			if((b-ti[j])*vi[j]<=p&&p<=(e-ti[j])*vi[j]){
				//printf("add\n");
				co++;
			}
		}
		printf("%d\n", co);
	}
}