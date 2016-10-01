#include "stdio.h"

char c;
int buf;

int main(){
	buf = 0;
	while((c=getchar())!=EOF){
		if(c==' ') buf++;
		else if(c==',') buf *= 8;
		else if(c=='.'){
			putchar('A'+buf);
			buf = 0;
		}
	}
}