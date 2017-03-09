#include "stdio.h"

int t,sp;
char s[256];
char stk[256];
bool isY;

int main(){
	scanf(" %d\n", &t);
	for(int k = 0; k < t; k++){
		sp = 0;
		isY = true;
		fgets(s, sizeof(s), stdin);
		for(int i = 0; s[i]!='\n' && isY; i++){
			switch(s[i]){
				case '(':
					s[sp++] = ')';
					break;
				case '[':
					s[sp++] = ']';
					break;
				case ')':
				case ']':
					if(sp==0){
						isY = false;
					}else{
						if(s[--sp]!=s[i]){
							isY = false;
						}
					}
					break;
			}
		}
		if(sp==0&&isY) printf("Yes\n");
		else printf("No\n");
		fflush(stdout);
	}
}