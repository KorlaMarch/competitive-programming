#include "stdio.h"

int n,q,x,y;
char c;
int p[100005];

int unionF(int x){
	return x==p[x]?x:(p[x]=unionF(p[x]));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}

	for(int i = 0; i < q; i++){
		scanf(" %c %d %d",&c,&x,&y);
		if(c=='c'){
			p[unionF(x)] = unionF(y);
		}else{
			if(unionF(x)==unionF(y)){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}
}