#include "stdio.h"
#include "algorithm"

int h,w,n;
std::pair<int,int> sp[200005];
int from[200005];
int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&sp[i].first,&sp[i].second);
	}
	std::sort(sp,sp+n);
	int mh = h%(2*w);
	for(int i = 0; i < n; i++){
		if(i%2==0){
			//forward
			if((i+mh)<=w){
				from[i+mh] = i;
			}else if(2*w-h-i-1>=0){
				from[2*w-h-i-1] = i;
			}else{
				from[] = i;
			}
		}else{
			//backward
			if()
		}
	}

	for(int i = n-1; i >= 0; i--){

	}

}