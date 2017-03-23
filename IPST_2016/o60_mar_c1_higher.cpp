#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n,k;
int xi[6005],hi[6005];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0, t = 0; t < k; i++,t++){
		scanf("%d%d",&xi[i],&hi[i]);
		int mx = -INF;
		int mn = INF;
		int delP = -1;
		for(int j = 0; j < i; j++){
			if(xi[j]==xi[i]){
				delP = j;
			}else if(hi[j]>hi[i]){
				if(xi[j]<xi[i]){
					mx = std::max(mx,xi[j]);
				}else{
					//xi[j]>xi[i]
					mn = std::min(mn,xi[j]);
				}
			}
		}

		if(mx==-INF&&mn==INF){
			printf("%d\n",n);
		}else{
			printf("%d\n",std::min(xi[i]-mx-1,mn-xi[i]-1));
		}

		if(delP!=-1){
			std::swap(xi[delP],xi[i]);
			std::swap(hi[delP],hi[i]);
			i--;
		}
	}
}