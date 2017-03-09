#include "stdio.h"

char s[50];
char st[1000];
int ptr,t;

int main(){
	scanf(" %d ",&t);
	for(int k = 0; k < t; k++){
		ptr = 0;
		while(1){
			if(fgets(s, sizeof(s), stdin) == NULL) break;
			if(s[0]=='\n') break;
			switch(s[0]){
				case '(':
					st[ptr++] = '(';
					break;
				case ')':
					while(st[--ptr]!='('){
						putchar(st[ptr]);
					}
					break;
				case '+':
				case '-':
					while(ptr != 0 && st[ptr-1] != '('){
						putchar(st[ptr-1]);
						ptr--;
					}
					st[ptr++] = s[0];
					break;
				case '*':
				case '/':
					while(ptr != 0 && (st[ptr-1] == '*' || st[ptr-1] == '/') ){
						putchar(st[ptr-1]);
						ptr--;
					}
					st[ptr++] = s[0];
					break;
				default:
					putchar(s[0]);
					break;
			}
		}
		while(ptr>0){
			putchar(st[--ptr]);
		}
		putchar('\n');
		if(k+1!=t) putchar('\n');
	}
}