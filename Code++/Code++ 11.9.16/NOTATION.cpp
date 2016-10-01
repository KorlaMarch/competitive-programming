#include "stdio.h"
#include "string.h"

char s[1000001];
int begi,len;

int main(){
	scanf(" %s",s);
	begi = 0;
	len = strlen(s);

	if(s[0]=='+'){
		begi = 1;
	}else if(s[0]=='-'){
		begi = 1;
		printf("-");
	}

	//find first & last
	int fi = -1,li = -1,dot = -1;
	for(int i = begi; i < len; i++){
		if(s[i]=='.'){
			dot = i;
		}else if(s[i]!='0'){
			if(fi==-1) fi = i;
			li = i;
		}
	}
	if(dot==-1) dot = len;
	if(fi==-1){
		// 0.0
		printf("0\n");
	}else{
		for(int i = fi; i <= li; i++){
			if(i-fi==1){
				putchar('.');
			}
			if(s[i]!='.'){
				putchar(s[i]);
			}
		}
		if(dot<fi) printf("(%d)\n",dot-fi);
		else if(dot-fi-1) printf("(%d)\n",dot-fi-1);
	}
	return 0;
}