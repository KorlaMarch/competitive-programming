#include "stdio.h"
#include "algorithm"

int n,fi,se,x;
int a[100005];
int b[100005];
int c[100005];


int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n-1; i++){
		scanf("%d",&b[i]);
	}
	for(int i = 0; i < n-2; i++){
		scanf("%d",&c[i]);
	}
	std::sort(a,a+n);
	std::sort(b,b+n-1);
	std::sort(c,c+n-2);

	for(int i = 0; i < n; i++){
		if(a[i]!=b[i]){
			printf("%d\n",a[i]);
			break;
		}
	}
	for(int i = 0; i < n-1; i++){
		if(b[i]!=c[i]){
			printf("%d\n",b[i]);
			break;
		}
	}
}