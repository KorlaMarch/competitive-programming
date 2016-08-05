#include "stdio.h"

int n,mx,len;
int a[100005];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
		if(!i||a[i]>a[i-1]){
			len++;
		}else{
			if(len>=mx) mx = len;
			len = 1;
		}
	}
	if(len>=mx) mx = len;
	printf("%d\n",mx);
}