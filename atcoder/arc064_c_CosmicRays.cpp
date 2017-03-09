#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "queue"
#include "vector"

typedef std::pair<double,int> pdi;

//point n -> start
//		n+1 -> end
double dist[1005][1005];
double minDist[1005];
bool isV[1005];
int xs,ys,xt,yt;
int n;
int xi[1005],yi[1005],ri[1005];
std::priority_queue<pdi , std::vector<pdi>, std::greater<pdi> > qu;

double squa(double x){
	return x*x;
}


int main(){
	scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d",&xi[i],&yi[i],&ri[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			dist[i][j] = dist[j][i] = std::max(0.0,sqrt( squa(xi[i]-xi[j]) + squa(yi[i]-yi[j]) )-ri[i]-ri[j]);
		}
	}

	for(int i = 0; i < n; i++){
		dist[i][n] = dist[n][i] = std::max(0.0,sqrt( squa(xi[i]-xs) + squa(yi[i]-ys) )-ri[i]);
	}
	for(int i = 0; i < n; i++){
		dist[i][n+1] = dist[n+1][i] = std::max(0.0,sqrt( squa(xi[i]-xt) + squa(yi[i]-yt) )-ri[i]);
	}

	dist[n][n+1] = dist[n+1][n] = sqrt( squa(xs-xt) + squa(ys-yt) );

	for(int i = 0; i < n+2; i++){
		minDist[i] = -1.0;
	}

	/*for(int i = 0; i < n+2; i++){
		for(int j = 0; j < n+2; j++){
			printf("%5.3f ",dist[i][j]);
		}
		printf("\n");
	}*/

	//run dijkstar
	qu.push({0.0,n});
	minDist[n] = 0.0;
	while(!qu.empty()){
		pdi no = qu.top();
		qu.pop();
		if(no.second==n+1){
			break;
		}else if(!isV[no.second]){
			//printf("%d %.10f\n",no.second,no.first);
			isV[no.second] = true;
			for(int i = 0; i < n+2; i++){
				if(!isV[i] && (minDist[i]==-1.0||no.first + dist[no.second][i]<minDist[i]) ){
					minDist[i] = no.first + dist[no.second][i];
					qu.push({minDist[i],i});
				}
			}
		}
	}
	printf("%.10f\n",minDist[n+1]);
}