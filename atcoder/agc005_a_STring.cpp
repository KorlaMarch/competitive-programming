#include "stdio.h"

char s[200005];
char st[200005];
int pt;

int main(){
	scanf(" %s",s);
	for(int i = 0; s[i]; i++){
		if(pt!=0&&st[pt-1]=='S'&&s[i]=='T') pt--;
		else st[pt++] = s[i];
	}
	printf("%d\n",pt);
}