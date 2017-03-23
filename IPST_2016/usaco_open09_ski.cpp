#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 100000000

typedef std::pair<int,int> PII;

int t,s,n,mi,li,ai,ci,di;
int minT[105];
int dyn[10005][105];
int mxDyn[10005];
std::vector<PII> train[10005];

int main(){
	scanf("%d%d%d",&t,&s,&n);
	for(int i = 0; i < s; i++){
		scanf("%d%d%d",&mi,&li,&ai);
		train[mi+li].push_back({mi,ai});
	}

	for(int i = 0; i <= 100; i++){
		minT[i] = INF;
	}

	for(int i = 0; i < n; i++){
		scanf("%d%d",&ci,&di);
		if(minT[ci]==0||di<minT[ci]){
			minT[ci] = di;
		}
	}
	for(int i = 1; i <= 100; i++){
		if(minT[i-1]<minT[i]){
			minT[i] = minT[i-1];
		}
		//printf("MT %d : %d\n",i,minT[i]);
	}

	dyn[0][1] = 1;
	for(int i = 1; i <= t; i++){		
		for(int j = 1; j <= 100; j++){
			if(i-minT[j]>=0&&dyn[i-minT[j]][j]){
				dyn[i][j] = std::max(dyn[i-1][j],dyn[i-minT[j]][j]+1);
			}else dyn[i][j] = dyn[i-1][j];
			mxDyn[i] = std::max(mxDyn[i],dyn[i][j]);
		}
		for(PII pi : train[i]){
			if(dyn[i][pi.second]==0||mxDyn[pi.first]>dyn[i][pi.second]) dyn[i][pi.second] = mxDyn[pi.first];
		}
		// for(int j = 1; j <= 5; j++){
		// 	printf("%d %d : %d\n", i,j, dyn[i][j]);
		// }
		// printf("\tMX %d : %d\n",i,mxDyn[i]);
	}

	printf("%d\n",mxDyn[t]-1);

}