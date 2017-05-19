#include "stdio.h"
#include "algorithm"
#include "queue"

typedef std::pair<long long,int> PII;

#define INF 10000000000LL

int n,c;
int ai[7005],bi[7005];
long long dif[7005];
long long ac[7005];
std::priority_queue<PII> qu;

long long countSumL(int lim, int x){
	long long sum = 0;
	for(int i = 0; i < lim; i++){
		if(dif[i]>x) sum += dif[i]-x;
	}
	return sum;
}

long long findMx(int lim, long long lb, long long cd){
	long long i = lb,j = lb+c,m,lm=lb+c;
	while(i<=j){
		m = (i+j)/2;
		if(countSumL(lim,m)+cd<=m){
			lm = m;
			j = m-1;
		}else{
			i = m+1;
		}
	}
	return lm;
}

int main(){
	scanf("%d%d",&n,&c);
	for(int i = 0; i < n; i++){
		scanf("%d",&ai[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&bi[i]);
		dif[i] = ai[i]-bi[i];
	}

	for(int i = 0; i < n; i++){
		long long mxD = -INF;
		for(int j = 0; j < i; j++){
			ac[j] = c;
			//mxD = std::max(mxD,dif[j]);
		}
		for(int j = 0; j < i; j++){
			ac[j] = c;
			mxD = std::max(mxD,dif[j]);
		}
		if(dif[i]<mxD){
			mxD = std::max(0LL,mxD-c);

			//cal new mx
			long long target = findMx(i,mxD,dif[i]);

			//try moving to target
			for(int j = 0; j < i; j++){
				if(dif[j]>target){
					const long long ch = std::min(ac[j],dif[j]-target);
					dif[j] -= ch;
					dif[i] += ch;
					ac[j] -= ch;
				}
			}

			if(dif[i]>target) return -1;

			for(int j = 0; j < i && dif[i]+1<target; j++){
				if(dif[j]==target){
					const long long ch = std::min(ac[j],std::min(dif[j]-target,target-dif[i]));
					dif[j] -= ch;
					dif[i] += ch;
					ac[j] -= ch;
				}
			}
			
			while(!qu.empty()) qu.pop();
			for(int j = 0; j < i; j++){
				if(ac[j]!=0) qu.push({dif[j],j});
			}
			while(!qu.empty()&&dif[i]+1<qu.top().first){
				PII pi = qu.top();
				qu.pop();
				long long ch;
				if(qu.empty()){
					ch = std::min(ac[pi.second],(dif[pi.second]-dif[i])/2);
				}else{
					ch = std::min(ac[pi.second],std::min((dif[pi.second]-dif[i])/2,pi.first-qu.top().first+1));
				}
				//printf("%lld %d : %lld\n",pi.first,pi.second,ch);
				if(ch==0) break;
				dif[i] += ch;
				dif[pi.second] -= ch;
				ac[pi.second] -= ch;
				if(ac[pi.second]!=0){
					qu.push({dif[pi.second],pi.second});
				}
			}
		}

		// 	//fill dif[i] to target
		// 	for(int j = 0; j < i && dif[i]+1<target; j++){
		// 		if(dif[j]==target){
		// 			const long long ch = std::min(ac[j],std::min(dif[j]-target,target-dif[i]));
		// 			dif[j] -= ch;
		// 			dif[i] += ch;
		// 			ac[j] -= ch;
		// 		}
		// 	}

		// 	//fill dif[i] to target
		// 	for(int j = 0; j < i && dif[i]+1<target; j++){
		// 		if(dif[j]>0){
		// 			const long long ch = std::min(ac[j],std::min(dif[j],target-dif[i]));
		// 			dif[j] -= ch;
		// 			dif[i] += ch;
		// 			ac[j] -= ch;
		// 		}
		// 	}
		// }
	}
	long long sum = 0;
	for(int i = 0; i < n; i++){
		//printf("DIF %d : %lld\n",i,dif[i]);
		if(dif[i]>=0) sum += bi[i];
		else sum += bi[i]+dif[i];
	}
	printf("%lld\n",sum);
}