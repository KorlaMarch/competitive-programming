#include "stdio.h"
#include "algorithm"

int n;
std::pair<int,int> in[40000];
int a[40000];

void printA(){
	for(int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void mergesort(int a[], int n, int th, int off){
	if(n<=1) return;
	else{
		mergesort(a,n/2,th,off);
		mergesort(a+n/2,n-n/2,th,off+n/2);
		int i,j;
		for(i = 0; i < n/2; i++){
			if(a[i]>=th) break;
		}
		for(j = n/2; j < n; j++){
			if(a[j]>=th) break;
		}
		j--;
		if(i<n/2&&j>=n/2){
			printf("%d %d\n",off+i+1,off+j+1);
			int tmp;
			for(int x = i, y = j; x<y; x++,y--){
				tmp = a[x];
				a[x] = a[y];
				a[y] = tmp;
			}
			//printA();
		}
	}
}

void quicksort(int a[], int n, int off){
	int pivot = off+n/2+1;
	if(n<=1) return;
	else{
		//printf("CALL %d\n",n);
		mergesort(a,n,pivot,off);
		quicksort(a,n/2,off);
		quicksort(a+n/2,n-n/2,off+n/2);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&in[i].first);
		in[i].second = i;
	}
	std::sort(in,in+n);
	for(int i = 0; i < n; i++){
		a[in[i].second] = i+1;
	}
	quicksort(a,n,0);
}