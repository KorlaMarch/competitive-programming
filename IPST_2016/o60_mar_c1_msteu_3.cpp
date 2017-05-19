#include "stdio.h"
#include "vector"
#include "algorithm"

struct Point{
	int x,y;
	int id;
	Point(int _x = 0, int _y = 0, int _id = 0) : x(_x), y(_y), id(_id) { }
};
struct Edge{
	int a,b;
	long long dis;
	Edge(int _a = 0, int _b = 0, long long _dis = 0) : a(_a), b(_b), dis(_dis) { }
};

long long distance(Point a, Point b){
	return (a.x-b.x)*(long long)(a.x-b.x) + (a.y-b.y)*(long long)(a.y-b.y);
}

int abs(int x){
	return x<0?-x:x;
}

bool cmp(Edge a, Edge b){
	return a.dis < b.dis;
}

std::vector<int> block[405][405];
std::vector<Edge> ed;
long long sum;
int n,a,b;
Point p[100005];
int par[100005];
int bc,bla,blb,sa,sb;

int getblockA(int x){
	return (x+a)/sa;
}

int getblockB(int y){
	return (y+b)/sb;
}

int unionF(int x){
	return x==par[x]?x:(par[x]=unionF(par[x]));
}

void addEdge(std::vector<int>& vecA, std::vector<int>& vecB){
	//printf("Add Edge");
	for(int x : vecA){
		for(int y : vecB){
			ed.push_back(Edge(x,y,distance(p[x],p[y])));
		}
	}
}

int getBSize(int bc){
	int x = 1, y = std::max(2*a+1,2*b+1),ans;
	while(x<=y){
		const int m = (x+y)/2;
		const int bl = (int)ceil((2*a+1)/(double)m)*(int)ceil((2*b+1)/(double)m);
		//printf("TE %d : %d (%d)\n",m,bl,bc);
		if(bl<=bc){
			ans = m;
			y = m-1;
			//printf("SI %d : %d (%d)\n",m,bl,bc);
		}else{
			x = m+1;
		}
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id = i;
		a = std::max(a,abs(p[i].x));
		b = std::max(b,abs(p[i].y));
	}

	bc = std::max( n/17 , 1);
	sa = sb = getBSize(bc);
	bla = (int)ceil((2*a+1)/(double)sa);
	blb = (int)ceil((2*b+1)/(double)sb);

	//printf("Tar %d : %d (%d %d)\n",bc,bla*blb,bla,blb);
	for(int i = 0; i < n; i++){
		block[getblockA(p[i].x)][getblockB(p[i].y)].push_back(i);
		par[i] = i;
	}

	//for each block
	for(int i = 0; i < bla; i++){
		for(int j = 0; j < blb; j++){
			//inside
			//if(block[i][j].size()==0) return -1;
			for(int x = 0; x < block[i][j].size(); x++){
				for(int y = x+1; y < block[i][j].size(); y++){
					ed.push_back(Edge(block[i][j][x],block[i][j][y],distance(p[block[i][j][x]],p[block[i][j][y]])));
				}
			}
			//between block
			if(j+1<blb) addEdge(block[i][j],block[i][j+1]);
			if(i+1<bla) addEdge(block[i][j],block[i+1][j]);
			if(i+1<bla&&j+1<blb) addEdge(block[i][j],block[i+1][j+1]);
			if(i>0&&j+1<blb) addEdge(block[i][j],block[i-1][j+1]);
		}
	}

	std::sort(ed.begin(),ed.end(),cmp);

	for(Edge& e : ed){
		if(unionF(e.a)!=unionF(e.b)){
			sum += e.dis;
			par[unionF(e.a)] = unionF(e.b);
		}
	}

	printf("%lld\n",sum);
}