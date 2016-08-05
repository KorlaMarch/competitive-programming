#include "stdio.h"

char s[5005];
char t[5005];
bool isFind;

int countPF(char s[]){
	int i;
	for(i = 1; s[i]; i++){
		if(s[i]!=s[i-1]) break;
	}
	return i;
}

int main(){
	scanf(" %s %s",s,t);
	isFind = true;
	for(int i = 0, j = 0; s[i] && isFind; i++){
		isFind = false;
		for(; t[j]; j++){
			if(s[i]==t[j]){
				j++;
				isFind = true;
				break;
			}
		}
	}
	if(!isFind){
		printf("No\n");
	}else{
		if(s[0]==t[0]&&countPF(s)>=countPF(t)) printf("Yes\n");
		else printf("No\n");
	}
}