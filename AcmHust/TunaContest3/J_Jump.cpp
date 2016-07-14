#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int n,r,c;
bool bit[1005];
bool isC[1005];

void printBit(){
	if(c++>=n+500) while(1);
	for(int i = 0; i < n; i++){
		putchar(bit[i]+'0');
	}
	putchar('\n');
	fflush(stdout);
}

int main(){
	srand(time(NULL));
	scanf("%d",&n);
	//find n/2 first
	bit[n] = '\0';
	while(1){
		printBit();
		scanf("%d",&r);
		if(r==n) return 0;
		else if(r){
			break;			
		}else{
			for(int j = 0; j < n; j++){
				bit[j] = rand()%2;
			}
		}
	}
	isC[0] = true;
	for(int i = 1; i < n; i++){
		bit[i-1] = !bit[i-1];
		bit[i] = !bit[i];
		printBit();
		scanf("%d",&r);
		if(r==n) return 0;
		else if(r){
			isC[i] = !isC[i-1];
		}else{
			isC[i] = isC[i-1];
		}
		bit[i-1] = !bit[i-1];
		bit[i] = !bit[i];
	}
	for(int i = 0; i < n; i++){
		if(!isC[i]){
			bit[i] = !bit[i];
		}
	}
	printBit();
	scanf("%d",&r);
	if(r==n) return 0;
	else{
		for(int i = 0; i < n; i++){
			bit[i] = !bit[i];
		}
		printBit();
	}
}