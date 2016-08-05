#include "stdio.h"
#include "string.h"

void filpOZ(int x);
void filpZ(int x);

int n;
char s[55];
long long oz[55];
long long c;

void filpOZ(int x){
	if(x>=n) return;
	if(s[x]=='1') filpZ(x+1);
	else{
		filpOZ(x+1);
		s[x] = '1';
		c += oz[n-x-1]+1;
	}
}

void filpZ(int x){
	if(x>=n) return;
	if(s[x]=='0') filpZ(x+1);
	else{
		filpOZ(x+1);
		s[x] = '0';
		c += oz[n-x-1]+1;
	}
}

int main(){
	scanf(" %s",s);
	n = strlen(s);
	//precompute oz
	oz[0] = 0;
	for(int i = 1; i <= n; i++){
		oz[i] = oz[i-1]*2+1;
	}
	filpZ(0);
	printf("%lld\n",c);
}