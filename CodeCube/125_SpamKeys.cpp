#include "stdio.h"

int n,co;
char s[100005];

bool match(char s[], const char t[], int si){
	for(int i = 0; i < si; i++){
		if(s[i]!=t[i]) return false;
	}
	return true;
}

bool isKeys(char c){
	switch(c){
		case 'Q':
		case 'W':
		case 'E':
		case 'A':
		case 'S':
		case 'D':
		case 'V':
			return true;
	}
	return false;
}

int main(){
	scanf("%d %s",&n,s);
	for(int i = 0; i < n; i++){
		if(i+7<n&&match(s+i,"SPACEBAR",8)){
			co++;
			i += 7;
		}else if(i+4<n&&match(s+i,"SHIFT",5)){
			co++;
			i += 4;
		}else if(isKeys(s[i])){
			co++;
		}
	}
	printf("%d\n",co);
}