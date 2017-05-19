#include "stdio.h"

int n,m,a,b;
int v[100005];

int getSubsum(){
	int mx = v[0];
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(sum<0) sum = 0;
		sum += v[i];
		if(sum>mx) mx = sum;
	}
	return mx;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
	}
	printf("%d\n",getSubsum());
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		v[a] = b;
		printf("%d\n",getSubsum());
	}
}