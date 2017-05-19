#include "stdio.h"
#include "vector"
#include "algorithm"
#define INF 1000000000

int n,l,u;
int hi[100005];

// bool check(int limH){
// 	int begin = 0, end = 0, bw = 0, minH;
// 	int j = 0, oj;
// 	hp.clear();
// 	for(int i = 0; i < n; i++){
// 		if(hi[i]>=limH) hp.push_back(i);
// 	}
// 	while (begin < n){
// 		//printf("%d ",begin);
// 		oj = j;
// 		if(j==hp.size()||hp[j]-begin+1>l) return false;
// 		else{
// 			if(begin+u>=n){
// 				if(begin+l-1-bw>=n) return false;
// 				else return true;
// 			}
// 			while(hp[j]-begin+1<=l&&j<hp.size()){
// 				j++;
// 			}
// 			end = begin+l-1;
			
// 			//try low
// 			if(j-oj>1 && end-bw < hp[j-1]){
// 				bw = std::min(hp[j-1]-hp[j-2]-1,hp[j-1]-(end-bw)-1);
// 				begin = hp[j-1];
// 			}else if(j<hp.size()){
// 				//try high
// 				minH = std::max(1,hp[j]-(begin+u-1));
// 				begin = hp[j]-minH+1;
// 				bw = std::min(begin-hp[j-1]-1,bw+(u-l));
// 			}

// 		}
// 	}
// 	return true;
// }

bool check(int limH){
	bool canEnd[100005];
	int qs[100005];
	int lastE = -1;
	canEnd[0] = true;
	qs[0] = 1;
	for(int i = 1; i <= n; i++){
		if(hi[i]>=limH){
			lastE = i;
		}
		if(lastE==-1||lastE<i-u+1||i-l<0) canEnd[i] = false;
		else if(qs[std::min(i-l,lastE-1)]-(i-u-1>=0? qs[i-u-1]: 0) == 0) canEnd[i] = false;
		else canEnd[i] = true;

		//printf("%d : %d %d (%d) : %d\n",i,i-u,std::min(i-l,lastE-1), lastE, canEnd[i]);
		qs[i] = qs[i-1];
		if(canEnd[i]) qs[i]++;
	}
	return canEnd[n];
}

int main(){
	scanf("%d%d%d",&n,&l,&u);
	for(int i = 1; i <= n; i++){
		scanf("%d",&hi[i]);
	}
	int x,y,m,lm=-1;
	x = 0, y = INF;
	while(x<=y){
		m = (x+y)/2;
		//printf("Try %d\n",m);
		if(check(m)){
			//printf("True\n");
			lm = m;
			x = m+1;
		}else{
			//printf("False\n");
			y = m-1;
		}
	}
	printf("%d\n",lm);
}