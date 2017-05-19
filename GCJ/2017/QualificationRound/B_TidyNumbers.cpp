#include "stdio.h"
#include "string.h"

int t,n;
char s[1000];

int main(){
	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		scanf(" %s",s);
		n = strlen(s);
		
		bool isP = false;
		for(int i = 1; s[i]; i++){
			if(s[i-1]>s[i]){
				do{
					i--;
					s[i]--;
				}while(i > 0 && s[i-1]>s[i]);
				
				printf("Case #%d: ",k);
				if(s[0]!='0'){
					putchar(s[0]);
				}
				for(int j = 1; j <= i; j++){
					putchar(s[j]);
				}
				for(i++; i < n; i++){
					putchar('9');
				}

				putchar('\n');

				isP = true;
				break;
			}
		}

		if(!isP){
			printf("Case #%d: %s\n",k,s);
		}
	}
}