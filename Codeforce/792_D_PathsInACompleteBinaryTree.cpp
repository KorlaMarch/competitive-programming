#include "stdio.h"

long long n,u;
int q,d,cd;
char s[100005];

int main(){
	scanf("%I64d %d",&n,&q);
	for(long long x = n+1; x % 2 == 0; x /= 2, d++);
	for(int i = 0; i < q; i++){
		scanf("%I64d %s",&u,s);
		cd = 0;
		for(long long x = u; x % 2 == 0; x /= 2, cd++);

		for(int i = 0; s[i]; i++){
			if(s[i]=='L'){
				if(cd!=0){
					cd--;
					u -= (1<<cd);
				}
			}else if(s[i]=='R'){
				if(cd!=0){
					cd--;
					u += (1<<cd);
				}
			}else{
				if(cd+1!=d){
					if(u/(1<<cd)%4==1){
						// == 1
						u += (1<<cd);
					}else{
						// == 3
						u -= (1<<cd);
					}
					cd++;
				}
			}
		}

		printf("%I64d\n",u);

	}

}