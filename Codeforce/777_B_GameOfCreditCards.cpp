#include "stdio.h"
#include "algorithm"

int n;
char sh[1005];
char mo[1005];
int minF,maxF;

int main(){
	scanf("%d %s %s",&n,sh,mo);
	std::sort(sh,sh+n);
	std::sort(mo,mo+n);
	//printf("%s %s\n",sh,mo);

	//cal minF
	for(int i = n-1, j = n-1; i >= 0; i--){
		if(sh[i]>mo[j]) minF++;
		else{
			j--;
		}
	}

	for(int i = n-1, j = n-1; i >= 0; i--){
		if(sh[i]<mo[j]){
			maxF++;
			j--;
		}
	}

	printf("%d\n%d\n",minF,maxF);
}