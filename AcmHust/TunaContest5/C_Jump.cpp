#include "stdio.h"

int n,q;
int a[205];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(int i = 0; i < q; i++){
		scanf("%d%d",&a,&b);
		if(a%2==b%2){
			
		}else printf("-1\n");
	}

}