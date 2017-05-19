#include "stdio.h"
#include "map"

int n,h,l,mx;
std::map<int,int> pc;
int xi[100005],yi[100005];

int main(){
	scanf("%d%d%d",&n,&h,&l);

	int lp = 0;
	for(int i = 0; i < n; i++){
		scanf("%d%d",&xi[i],&yi[i]);
		//del pole
		while(xi[i]-xi[lp]>h){
			for(int j = yi[lp]; j >= yi[lp]-l && j >= 0; j--){
				pc[j]--;
			}
			lp++;
		}
		//add pole
		for(int j = yi[i]; j >= yi[i]-l && j >= 0; j--){
			pc[j]++;
			if(pc[j]>mx) mx = pc[j];
		}
	}

	printf("%d\n",mx);
}