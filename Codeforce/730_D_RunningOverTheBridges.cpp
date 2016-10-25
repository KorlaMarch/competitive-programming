#include "stdio.h"
#include "vector"

int n,r;
int l[200005],t[200005];

int main(){
	scanf("%d%d",&n,&r);
	for(int i = 0; i < n; i++){
		scanf("%d",&l[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&t[i]);
		if(l[i]>t[i]){
			printf("-1\n");
			return 0;
		}
	}

	int bonus = 0,st = 0;
	for(int i = 0; i < n; i++){
		if(2*l[i]-bonus>t[i]){
			t[i]-(2*l[i]-bonus) 
		}else{
			st += 2*l[i]-bonus;
			bonus = 0;
		}
	}

	for()
}