#include "stdio.h"

int fm;
int a,b;

int main(){
	scanf("%d %d:%d",&fm,&a,&b);
	
	if(b>=60){
		b = b%10;
	}

	if(fm==12){
		if(a>12||a==0){
			if(a%10) a = a%10;
			else a = 10;
		}
	}else{
		if(a>23){
			a = a%10;
		}
	}

	printf("%02d:%02d\n",a,b);
}