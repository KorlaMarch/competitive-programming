#include "stdio.h"

int n,k,co;
bool isY[55];
int num[55];
char s[5];

int main(){
	scanf("%d%d",&n,&k);

	for(int i = 0; i < n-k+1; i++){
		scanf(" %s",s);
		if(s[0]=='Y'||s[0]=='y'){
			isY[i] = true;
		}else{
			isY[i] = false;
		}
	}
	
	co = 1;
	for(int i = 0; i < k; i++){
		num[i] = co++;
	}

	if(!isY[0]){
		num[k-1] = num[0];
	}
	for(int i = 1; i < n-k+1; i++){
		if(isY[i]){
			num[i+k-1] = co++;
		}else{
			num[i+k-1] = num[i];
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%c%c ",num[i]/26+'A',num[i]%26+'a');
	}
}