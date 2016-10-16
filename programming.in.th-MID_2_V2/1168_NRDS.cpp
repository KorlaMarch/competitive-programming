#include "stdio.h"
#include "algorithm"

int q,co;
long long n;
int nrds[512];

void genAll(int sig, int num){
	if(sig>=10){
		nrds[co++] = num;
	}else{
		genAll(sig+1,num);
		genAll(sig+1,num*10 + sig);
	}
}

int main(){
	genAll(1,0);
	std::sort(nrds,nrds+512);

	scanf("%d",&q);
	for(int k = 0; k < q; k++){
		scanf("%lld",&n);
		if(n>=512) printf("-1\n");
		else printf("%d\n",nrds[n]);
	}
}