#include "stdio.h"

int n,ai;
bool isAc;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&ai);
		if(isAc){
			if(ai==0){
				printf("NO\n");
				return 0;
			}else if(ai%2==0){
				isAc = true;
			}else{
				isAc = false;
			}
		}else{
			if(ai%2==0){
				isAc = false;
			}else{
				isAc = true;
			}
		}
	}

	if(isAc){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
}