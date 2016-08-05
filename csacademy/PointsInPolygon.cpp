#include "stdio.h"
#include "algorithm"
#include "vector"

typedef std::pair<int,int> Pii;

struct geoVector{
	long long x,y;
	
	geoVector(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}

	//cross product
	long long operator^(const geoVector& a){
		return this->x*a.y-a.x*this->y;
	}
};

long long checkCross(Pii a, Pii b, Pii c){
	return geoVector(b.first-a.first,b.second-a.second)^geoVector(c.first-a.first,c.second-a.second);
}

int n,m,x,y,co;
Pii ver[2005];

int getSt(long long x){
	if(x<0) return -1;
	else if(x==0) return 0;
	else return 1;	
}

bool checkPoint(int x, int y){
	int r1,r2,r3,r4;
	int inter = 0;
	for(int i = 0; i < n; i++){
		r1 = getSt(checkCross({x,y},{13,10000000},ver[i]));
		r2 = getSt(checkCross({x,y},{13,10000000},ver[(i+1)%n]));
		r3 = getSt(checkCross(ver[i],ver[(i+1)%n],{x,y}));
		r4 = getSt(checkCross(ver[i],ver[(i+1)%n],{13,10000000}));
		//printf("%d %d %d %d\n",r1,r2,r3,r4);
		if(r3==0&&r1!=r2){
			return true;
		}else if(r1!=r2&&r3!=r4){
			if(r1==0||r2==0){
				inter++;
			}else{
				inter += 2;
			}
		}
	}
	//printf("%d %d : %d\n",x,y,inter);
	return (inter/2)%2;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&ver[i].first,&ver[i].second);
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
		if(checkPoint(x,y)) co++;
	}
	printf("%d\n",co);
} 