#include "stdio.h"

int a, b, c;

int main(){
	while(scanf("%d%d%d",&a, &b, &c) == 3){
		for(int x = 1; x <= c; x++){
			int y = (c- a*x)/b;
			if((c- a*x)%b==0){
				printf("%d * %d + %d * %d = %d\n", a, x, b, y, c);
				break;	
			}
		}
	}
}
