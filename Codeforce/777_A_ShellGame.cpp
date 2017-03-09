#include "stdio.h"

int n,x;
int pos[15][3];
int main(){
	scanf("%d%d",&n,&x);
	
	pos[0][0] = 0;
	pos[0][1] = 1;
	pos[0][2] = 2;

	for(int i = 1; i < 12; i++){
		if(i%2){
			pos[i][0] = pos[i-1][1];
			pos[i][1] = pos[i-1][0];
			pos[i][2] = pos[i-1][2];
		}else{
			pos[i][0] = pos[i-1][0];
			pos[i][1] = pos[i-1][2];
			pos[i][2] = pos[i-1][1];
		}
	}

	printf("%d\n",pos[n%12][x]);
}