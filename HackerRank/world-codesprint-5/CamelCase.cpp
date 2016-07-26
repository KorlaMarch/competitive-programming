#include "stdio.h"

char s[100005];
int c;

int main(){
	scanf(" %s",s);
	for(int i = 0; s[i]; i++){
		if(s[i]>='A'&&s[i]<='Z') c++;
	}
	printf("%d\n",c+1);
}