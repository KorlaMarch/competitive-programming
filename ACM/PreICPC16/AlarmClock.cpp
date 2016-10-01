#include "stdio.h"
#include "algorithm"
#include "stdlib.h"

int h1,m1,h2,m2;

int main(){
	scanf("%d%d %d%d",&h1,&m1,&h2,&m2);
	if(h1>h2) std::swap(h1,h2);
	if(m1>m2) std::swap(m1,m2);
	printf("%d\n",std::min(h2-h1,h1+24-h2)+std::min(m2-m1,m1+60-m2));
}