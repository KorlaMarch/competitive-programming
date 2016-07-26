#include "stdio.h"

int n;
char s[100005];
bool isU[256];
int main(){
	scanf("%d",&n);
	for(int t = 0; t < n; t++){
		scanf(" %s",s);
		for(int i = 0; i < 256; i++) isU[i] = false;
		int c = 0;
		for(int i = 0; s[i]; i++){
			if(!isU[s[i]]){
				isU[s[i]] = true;
				c++;
			}
		}
		printf("%d\n",c);
	}
}