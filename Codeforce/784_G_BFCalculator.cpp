#include "stdio.h"
#include "string.h"

int sum;
int x;
char c;
char s[10];

void printRep(char c, int x){
	for(; x > 0; x--) putchar(c);
}

int main(){
	scanf("%d",&sum);
	while(scanf("%c%d",&c,&x)==2){
		//if(c=='X') break;
		if(c=='+') sum += x;
		else sum -= x;

		//printf("%c %d\n",c,x);
	}
	//printf("%d\n",sum);
	sprintf(s,"%d",sum);
	for(int i = 0; s[i]; i++){
		printRep('+',s[i]);
		printf(".>\n");
	}
}