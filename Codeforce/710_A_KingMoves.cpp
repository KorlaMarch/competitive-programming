#include "stdio.h"

char r,c;

bool isR(){
	return r=='1'||r=='8';
}

bool isC(){
	return c=='a'||c=='h';
}

int main(){
	scanf(" %c%c", &c,&r);
	if(isR()&&isC()){
		printf("3\n");
	}else if(isR()||isC()){
		printf("5\n");
	}else{
		printf("8\n");
	}
}