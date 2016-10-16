#include "stdio.h"

int x,n,p,sump;


int main(){
	scanf("%d%d",&x,&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&p);
		sump += p;
	}
	printf("%d\n",x*n+x-sump);
}