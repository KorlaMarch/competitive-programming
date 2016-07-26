#include "stdio.h"

int n,x;
long long c;
int num[1500005];
int ind[1500005];

void merge(int a[], int na, int b[], int nb, int o[]){
	for(int i = 0, j = 0; i<na||j<nb; ){
		if(i<na&&(j>=nb||a[i]<b[j])){
			o[i+j] = a[i];
			i++;
		}else{
			o[i+j] = b[j];
			c += na-i;
			j++;
		}
	}
}

void mergesort(int a[], int n){
	if(n<=1) return;
	mergesort(a,n/2);
	mergesort(a+n/2,n-n/2);
	merge(a,n/2,a+n/2,n-n/2,ind);
	for(int i = 0; i < n; i++){
		a[i] = ind[i];
	}
}

int main(){
	scanf("%d",&n);
	n /= 2;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		ind[x] = i+1;
	}

	for(int i = 0; i < n; i++){
		scanf("%d",&num[i]);
		num[i] = ind[num[i]];
	}
	mergesort(num,n);
	printf("%lld\n",c);
	return 0;
}