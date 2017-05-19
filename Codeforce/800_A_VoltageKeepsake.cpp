#include "stdio.h"
#include "algorithm"

typedef std::pair<double,double> PII;

int n,p,a,b;
PII device[100005];
double sumt;

bool cmp(PII a, PII b){
	return a.second < b.second;
}

int main(){
	scanf("%d%d",&n,&p);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&a,&b);
		device[i].first = (double)a;
		device[i].second = (double)b/(double)a;
	}
	std::sort(device,device+n,cmp);

	int i;
	for(i = 0; i+1 < n; i++){
		if(sumt+(device[i+1].second-device[i].second)*device[i].first/p < device[i+1].second){
			sumt += (device[i+1].second-device[i].second)*device[i].first/p;
			device[i+1].first += device[i].first;
			//printf("Case 1 : %.5f %.5f\n",sumt,device[i+1].first);
		}else{
			sumt += (device[i].second-sumt)*device[i].first/(device[i].first-p);
			break;
		}

	}

	if(i+1==n){
		if(p>=device[i].first) printf("-1\n");
		else{
			sumt += (device[i].second-sumt)*device[i].first/(device[i].first-p);
			printf("%.9f\n",sumt);
		}
	}else printf("%.9f\n",sumt);
}