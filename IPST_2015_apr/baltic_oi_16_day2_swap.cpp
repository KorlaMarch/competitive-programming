#include "stdio.h"
#include "algorithm"

#define INF 1000000

int n;
int x[200005];

void cmpChange(int a, int b, int va, int vb){
	int mna,mnb;

	if(2*a+1<=n) mna = std::min(x[2*a],x[2*a+1]);
	else if(2*a<=n) mna = x[2*a];
	else mna = INF;

	if(2*b+1<=n) mnb = std::min(x[2*b],x[2*b+1]);
	else if(2*b<=n) mnb = x[2*b];
	else mnb = INF;

	if(va>vb) std::swap(va,vb);

	if(mna < va && mnb < va){
		
	}else if(mna < va){
		x[a] = vb;
		x[b] = va;
	}else{
		x[a] = va;
		x[b] = vb;
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&x[i]);
	}
	for(int i = 1; 2*i <= n; i++){
		if(2*i+1<=n){
			if(x[2*i]<x[i]&&x[2*i]<x[2*i+1]){
				std::swap(x[i],x[2*i]);
			}else if(x[2*i+1]<x[i]&&x[2*i+1]<x[2*i]){
				std::swap(x[i],x[2*i+1]);
				cmpChange(2*i,2*i+1,x[2*i],x[2*i+1]);
			}
		}else{
			if(x[i]>x[2*i]) std::swap(x[i],x[2*i]);
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d ",x[i]);
	}

}