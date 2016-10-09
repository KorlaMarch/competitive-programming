#include "stdio.h"
#include "algorithm"
#include "unordered_set"

int n,mxY;
int yi[50005];
int xi[50005];
std::unordered_set<int> isU;

bool canDo(int m){
	isU.clear();
	for(int i = 0; i < n; i++){
		xi[i] = yi[i];
		while(xi[i]!=0&&(xi[i]>m||isU.count(xi[i])) ){
			xi[i] /= 2;
		}
		if(xi[i]==0) return false;
		isU.insert(xi[i]);
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&yi[i]);
		mxY = std::max(mxY,yi[i]);
	}

	int x,y,m,lm;
	for(x=0,y=mxY; x <= y; ){
		m = (x+y)/2;
		if(canDo(m)){
			y = m-1;
			lm = m;
		}else{
			x = m+1;
		}
	}
	canDo(lm);
	for(int i = 0; i < n; i++){
		printf("%d ", xi[i]);
	}
}