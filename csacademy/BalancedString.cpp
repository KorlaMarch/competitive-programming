#include "stdio.h"

int t,mm,mx,len;
char s[50005];
int ac[50005];

int main(){
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		scanf(" %s",s);
		
		for(len = 0; s[len]; len++){
			ac[len] = 0;
		}
		int i;
		for(i = 0; i < len; i++){
			mm = len;
			mx = 0;
			for(int j = 0; j < len; j++){
				const int p = (j-i+len)%len;
				if(s[j]=='A'){
					ac[p]++;
				}
				if(ac[p]<mm) mm = ac[p];
				if(ac[p]>mx) mx = ac[p];
			}
			if(mx-mm>1){
				break;
			}
		}
		if(i==len){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
}