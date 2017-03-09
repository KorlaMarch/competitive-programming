#include "stdio.h"
#include "algorithm"

#define INF 1000000000

struct point{
	int x,y,z;
	point(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}
};

int n;
point cube[20][2];
long long area[20];

// maxP = max of min
// minP = min of max
void findArea(int i, int c, point maxP, point minP){
	if(i==n){
		if(c>=2&&maxP.x<minP.x && maxP.y<minP.y && maxP.z<minP.z){
			area[c] += (minP.x-maxP.x)*(long long)(minP.y-maxP.y)*(minP.z-maxP.z);
		}
	}else{
		//exclude
		findArea(i+1,c,maxP,minP);

		//include
		maxP.x = std::max(maxP.x,std::min(cube[i][0].x,cube[i][1].x));
		maxP.y = std::max(maxP.y,std::min(cube[i][0].y,cube[i][1].y));
		maxP.z = std::max(maxP.z,std::min(cube[i][0].z,cube[i][1].z));

		minP.x = std::min(minP.x,std::max(cube[i][0].x,cube[i][1].x));
		minP.y = std::min(minP.y,std::max(cube[i][0].y,cube[i][1].y));
		minP.z = std::min(minP.z,std::max(cube[i][0].z,cube[i][1].z));

		findArea(i+1,c+1,maxP,minP);
	}

}

long long facTo(int n, int x){
	return n<x?1:n*facTo(n-1,x);
}

long long combi(int n, int r){
	return facTo(n,r+1)/facTo(r,1);
}

int main(){
	while(scanf("%d",&n)&&!feof(stdin)){
		for(int i = 0; i < n; i++){
			scanf("%d%d%d %d%d%d",&cube[i][0].x,&cube[i][0].y,&cube[i][0].z,&cube[i][1].x,&cube[i][1].y,&cube[i][1].z);
			area[i] = 0;
		}
		area[n] = 0;

		if(n==1){
			printf("0\n");
		}else{
			//solve by using inclusion-exclusion principle
			findArea(0,0,point(-INF,-INF,-INF),point(INF,INF,INF));

			for(int i = n; i >= 2; i--){
				printf("%d : %lld\n",i,area[i]);
			}

			for(int i = n; i >= 2; i--){
				printf("%d : %lld\n",i,area[i]);
				for(int j = i-1; j >= i-2 && j >= 2; j--){
					area[j] -= (i-1)*area[i];
				}
			}

			printf("%lld\n",area[2]);
		}
	}
}