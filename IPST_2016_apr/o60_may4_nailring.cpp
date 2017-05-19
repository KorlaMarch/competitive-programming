#include "stdio.h"
#include "string.h"

int n;
char s[5005];
long long dyn[5005][5005];
long long k;

int main(){
	scanf(" %s %lld",s,&k);
	n = strlen(s);
	k--;

	//dp to find number of ways
	dyn[n][0] = 1;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < n; j++){
			if(s[i]=='.'){
				//both
				if(j){
					if(dyn[i+1][j+1]==-1||dyn[i+1][j-1]==-1){
						dyn[i][j] = -1;
					}else{
						dyn[i][j] = dyn[i+1][j+1]+dyn[i+1][j-1];
						//prevent overflow
						if(dyn[i][j]>k){
							dyn[i][j] = -1;
						}
					}
				}else dyn[i][j] = dyn[i+1][j+1];
			}else if(s[i]=='('){
				// '('
				dyn[i][j] = dyn[i+1][j+1];
			}else{
				// ')'
				if(j) dyn[i][j] = dyn[i+1][j-1];
				else dyn[i][j] = 0;
			}
			//printf("%d %d : %lld\n",i,j,dyn[i][j]);
		}
	}

	//generate string
	int oc = 0;
	for(int i = 0; i < n; i++){
		//printf(" i = %d : %lld , %d\n",i,k,oc);
		if(s[i]=='.'){
			if(dyn[i+1][oc+1]==-1||dyn[i+1][oc+1]>k){
				s[i] = '(';
			}else{
				s[i] = ')';
				k -= dyn[i+1][oc+1];
			}
		}

		putchar(s[i]);
		if(s[i]=='('){
			oc++;
		}else{
			oc--;
		}
	}
	putchar('\n');
}