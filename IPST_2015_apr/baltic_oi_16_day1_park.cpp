#include "stdio.h"
#include "queue"
#include "math.h"
#include "vector"
#include "set"

#define EPSI 0.0000001

double sq(double x);
double getDis(int a, int b);

struct line{
	double dis;
	int a,b;
	line(int _a = 0, int _b = 0) : a(_a), b(_b) {
		dis = getdis(a,b);
	}
	bool operator()(line a, line b){
		return a.dis>b.dis;
	}
};

struct Point{
	int x,y,ox,oy;
	double angle,dis;
	Point(int _x = 0, int _y = 0, int _ox = 0, int _oy = 0, double _dis) : x(_x), y(_y), ox(_ox), oy(_oy), dis(_dis){
		angle = atan2(y-oy, x-ox);
	}
	bool operator()(Point a, Point b){
		return a.angle < b.angle;
	}
};

int n,m,w,h;
int cx[2005],cy[2005],cr[2005];
std::priority_queue<line, std::std::vector<line>, line> qu;
std::set<Point,Point> point[2005];
bool isCon[2005][2005];

double sq(double x){
	return x*x;
}

double abs(double x){
	return x<0?-x:x;
}

double getDis(int a, int b){
	return sqrt(sq(cx[a]-cx[b])+sq(cy[a]-cy[b]))-cr[a]-cr[b];
}

bool check(line li){
	double ang;
	if(point[li.a].size>2){
		ang = atan2(cy[tmp.b]-cy[tmp.a],cx[tmp.b]-cx[tmp.a]);
		auto it = point[li.a].lower_bound(ang);
		auto it2 = point[li.a].upper_bound(ang);
		if(it!=point[li.a].end()&&abs(it->angle-ang)<EPSI) return false;
		
		if(it==point[li.a].begin()) it = point[li.a].end();
		if(it2==point[li.a].end()) it2 = point[li.a].begin();

		it--,it2++;
		if(it2==point[li.a].end()) it2 = point[li.a].begin();

		if(it2)
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&w,&h);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d",&cx[i],&cy[i],&r[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			qu.push(i,j);
		}
	}

	while(!qu.empty()){
		line tmp = qu.top();
		qu.pop();
		if(check(tmp)){
			isCon[tmp.a][tmp.b] = true;
			isCon[tmp.b][tmp.a] = true;

			point[tmp.a].push(Point(cx[tmp.b],cy[tmp.b],cx[tmp.a],cy[tmp.a],tmp.dis));
			point[tmp.b].push(Point(cx[tmp.a],cy[tmp.a],cx[tmp.b],cy[tmp.b],tmp.dis));
		}
	}

	//begin bfs with 0 0
	for(int 

}