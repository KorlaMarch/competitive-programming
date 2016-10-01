#include "stdio.h"

int n;
int oc,op,ep;
bool isOdd[51][51];

int main(){
	scanf("%d",&n);
	oc = n*n/2+1;
	for(int i = 0; i < n; i++){
		isOdd[i][n/2] = isOdd[n/2][i] = true;
		oc -= 2;
	}
	oc++;
	if(oc%4!=0) while(1);
	else{
		for(int i = 0; i < n/2 && oc > 0; i++){
			for(int j = 0; j < n/2 && oc > 0; j++){
				isOdd[i][j] = isOdd[i][n-j-1] = isOdd[n-i-1][j] = isOdd[n-i-1][n-j-1] = true;
				oc -= 4;
			}
		}
		op = 1;
		ep = 2;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(isOdd[i][j]){
					printf("%d ",op);
					op += 2;
				}else{
					printf("%d ", ep);
					ep += 2;
				}
			}
			printf("\n");
		}
	}
}