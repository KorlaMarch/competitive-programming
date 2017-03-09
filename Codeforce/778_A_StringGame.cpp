#include "stdio.h"
#include "string.h"

int n,x,lm,m;
char t[200005];
char p[200005];
int rem[200005];

int cando(int x){
	int j = 0;
	for(int i = 0; i < n && j < m; i++){
		if(rem[i]>x&&p[j]==t[i]){
			j++;
		}
	}
	return j==m;
}

int main(){
	scanf(" %s %s",t,p);
	n = strlen(t);
	m = strlen(p);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		rem[x-1] = i+1;
	}

	int i = 0, j = n-1; 
	while(i<=j){
		int m = (i+j)/2;
		if(cando(m)){
			lm = m;
			i = m+1;
		}else{
			j = m-1;
		}
	}
	printf("%d\n",lm);
}