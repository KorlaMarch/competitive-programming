#include "stdio.h"
#include "stdlib.h"

int n,m,co;
int x1,y1,x2,y2;

int main(){
	scanf("%d%d %d%d %d%d",&n,&m,&x1,&y1,&x2,&y2);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(abs(i-x1)+abs(j-y1)==abs(i-x2)+abs(j-y2)){
				co++;
			}
		}
	}
	printf("%d\n",co);
}