#include "stdio.h"
#include "math.h"
#include "algorithm"

int ans[205];
int t,k;

void genNum(int p, int num, int u){
	if(u>=3||p>9){
		for(int i = 1; i <= 200; i++){
			if(abs(i-num)<abs(i-ans[i])||(abs(i-num)==abs(i-ans[i])&&num>ans[i])){
				ans[i] = num;
			}
		}
	}else{
		for(int i = 0; u+i <= 3; i++){
			if(p%3!=0) genNum(p+1,num,u+i);
			if(p==8) genNum(0,num,u+i);
			else if(p==0) genNum(10,num,u+i);
			else genNum(p+3,num,u+i);
			num = 10*num+p;
		}
	}
}

int main(){
	genNum(1,0,0);
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d",&k);
		printf("%d\n",ans[k]);
	}
}