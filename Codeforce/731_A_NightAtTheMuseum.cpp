#include "stdio.h"
#include "algorithm"

char str[1000];
char lsC,crC;
int cmove;

int main(){
	scanf(" %s",str);
	lsC = 0;
	for(int i = 0; str[i]; i++){
		crC = str[i]-'a';
		if(crC>lsC) cmove += std::min(crC-lsC,lsC+26-crC);
		else cmove += std::min(lsC-crC,crC+26-lsC);

		lsC = crC;
	}
	printf("%d\n",cmove);
}