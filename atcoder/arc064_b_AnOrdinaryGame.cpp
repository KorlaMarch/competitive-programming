#include "stdio.h"
#include "string.h"
char s[100005];

int main(){
	scanf("%s",s);
	int len = strlen(s);
	if(len%2){
		if(s[0]==s[len-1]){
			printf("Second\n");
		}else{
			printf("First\n");
		}
	}else{
		if(s[0]!=s[len-1]){
			printf("Second\n");
		}else{
			printf("First\n");
		}
	}
}