#include "stdio.h"

int n,mx,mxP;
char p[75][25];
int ki,mi,ti;
long long sum;

int main(){
	mx = -1;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf(" %s %d%d",p[i],&ki,&mi);
		ti = 0;
		while(mi>=ki){
			mi -= ki-2;
			ti++;
		}
		sum += ti;
		if(ti>mx){
			mx = ti;
			mxP = i;
		}
	}
	printf("%lld\n%s\n",sum,p[mxP]);
}