#include "stdio.h"

int n,c;
int pat[1000];
char s[1000];

bool isV(char c){
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;
		default:
			return false;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&pat[i]);
	}
	int i;
	for(i = 0; i < n; i++){
		scanf(" %[^\n]",s);
		c = 0;
		for(int j = 0; s[j] != '\0'; j++){
			if(isV(s[j])) c++;
		}
		if(c!=pat[i]) break;
	}
	if(i==n) printf("YES\n");
	else printf("NO\n");
}