#include "stdio.h"

int ft[300];
int n,ac,rc;
int minL;
char s[100005];
bool isH[300];

void chFT(int ind, int v){
	if(ft[ind]==0){
		rc++;
	}
	ft[ind] += v;
	if(ft[ind]==0) rc--; 
}

int main(){
	scanf("%d %s",&n,s);
	for(int i = 0; i < n; i++){
		if(!isH[s[i]]){
			isH[s[i]] = true;
			ac++;
		}
	}
	if(ac==1){
		printf("1\n");
		return 0;
	}
	minL = n+1;
	for(int i = 0, j = 0; i < n; i++){
		chFT(s[i],1);
		if(ac==rc){
			for(; j < i && ac==rc; j++){
				chFT(s[j],-1);
			}
			if(i-j<minL) minL = i-j;
		}
	}
	printf("%d\n",minL+2);
}