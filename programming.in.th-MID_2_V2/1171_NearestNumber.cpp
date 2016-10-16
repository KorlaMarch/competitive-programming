#include "stdio.h"

char str[50],str2[50];
long long a;
int k,n,n2,rk,t;

int main(){
	for(scanf("%d",&t); t > 0; t--){
		scanf("%lld %d",&a,&k);
		
		if(k==0){
			printf("0\n");
			continue;
		}

		for(n = 0, rk = 0; a != 0; a /= 10, n++){
			str[n] = a%10;
			rk += a%10;
		}

		if(rk>k){
			//try del
			int del = rk-k;
			for(int i = 0; i < n; i++){
				if(del>str[i]){
					del -= str[i];
					str[i] = 0;
				}else{
					str[i] -= del;
					break;
				}
			}
			//try add
			for(int i = 0; i < n; i++){
				str2[i] = 0;
			}
			if(str[n-1]==9){
				str2[n] = 1;
				n2 = n+1;
			}else{
				str2[n-1] = str[n-1]+1;
				n2 = n;
			}
		}else if(rk<k){
			//try add
			int del = k-rk;
			for(int i = 0; i < n; i++){
				if(del>9-str[i]){
					del -= 9-str[i];
					str[i] = 9;
				}else{
					str[i] += del;
					del = 0;
					break;
				}
			}
			if(del != 0){
				for(; del != 0; n++){
					if(del>9){
						del -= 9;
						str[n] = 9;
					}else{
						str[n] = del;
						del = 0;
					}
				}
			}
		}

		for(int i = n-1; i >= 0; i--){
			putchar(str[i]+'0');
		}
		putchar('\n');
	}
}