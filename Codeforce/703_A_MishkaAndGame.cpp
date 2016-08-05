#include "stdio.h"

int n,m,c,a,b;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&m,&c);
		if(m>c) a++;
		else if(m<c) b++;
	}
	if(a==b){
		printf("Friendship is magic!^^\n");
	}else if(a>b){
		printf("Mishka\n");
	}else{
		printf("Chris\n");
	}
}