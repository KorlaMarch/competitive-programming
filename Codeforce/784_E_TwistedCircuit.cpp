#include "stdio.h"

int a,b,c,d;
int x[4];
int f[2];

int orf(int a, int b){
	return a^b;
}

int andf(int a, int b){
	return a&b;
}

int xorf(int a, int b){
	return a|b;
}

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	x[0] = orf(a,b);
	x[1] = xorf(c,d);
	x[2] = andf(b,c);
	x[3] = orf(a,d);

	f[0] = andf(x[0],x[1]);
	f[1] = xorf(x[2],x[3]);

	printf("%d\n",orf(f[0],f[1]));
	//printf("0\n");
}