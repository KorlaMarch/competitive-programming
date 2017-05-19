#include "stdio.h"
#include "vector"
#include "algorithm"

#define INF 1000000000

typedef std::pair<int,int> PII;

struct Edge{
	int a,b,w,id;
	bool isCy;
	Edge(int _a = 0, int _b = 0, int _w = 0, int _id = 0) : a(_a), b(_b), w(_w), id(_id) {
		isCy = false;
	}
};

int n,q,k,s,t,c,a,b,w;
std::vector<PII> edge[100005];
std::vector<Edge> edgeList;
bool isV[100005];
bool isCy[100005];

int sumw[400005];
int cyCount[400005];
int noCount[400005];
int mx[400005];
int mxCount[400005];
int lazyAdd[400005];
int lazySet[400005];
bool isSet[400005];

bool isIntersect(int x1, int y1, int x2, int y2){
	return (x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1)||(x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2);
}

int findCycle(int x, int o){
	isV[x] = true;
	for(PII pi : edge[x]){
		if(pi.first!=o){
			if(isV[pi.first]){
				isCy[x] = true;
				return pi.first;
			}else{
				int re = findCycle(pi.first,x);
				if(re){
					if(re==-1) return -1;
					else{
						isCy[x] = true;
						if(re==x) return -1;
						else return re;
					}
				}
			}
		}
	}
	return 0;
}

void updateNode(int no){
	sumw[no] = sumw[no*2+1] + sumw[no*2+2];
	if(mx[no*2+1]==mx[no*2+2]){
		mx[no] = mx[no*2+1];
		mxCount[no] = mxCount[no*2+1]+mxCount[no*2+2];
	}else if(mx[no*2+1]>mx[no*2+2]){
		mx[no] = mx[no*2+1];
		mxCount[no] = mxCount[no*2+1];
	}else{
		mx[no] = mx[no*2+2];
		mxCount[no] = mxCount[no*2+2];
	}
}

void makeSeg(int no, int i, int j){
	if(i==j){
		sumw[no] = edgeList[i].w;
		noCount[no] = 1;
		if(edgeList[i].isCy){
			mx[no] = edgeList[i].w;
			mxCount[no] = 1;
			cyCount[no] = 1;
		}else{
			mx[no] = -INF;
			mxCount[no] = 0;
			cyCount[no] = 0;
		}
	}else{
		makeSeg(no*2+1,i,i+(j-i)/2);
		makeSeg(no*2+2,i+(j-i)/2+1,j);

		noCount[no] = noCount[no*2+1] + noCount[no*2+2];
		cyCount[no] = cyCount[no*2+1] + cyCount[no*2+2];

		updateNode(no);
	}
}

void makeLazy(int no, int k, int c){
	if(k==1){
		//add
		sumw[no] += c*noCount[no];
		if(mx[no]!=-INF){
			mx[no] += c;
		}
		if(isSet[no]){
			lazySet[no] += c;
		}else{
			lazyAdd[no] += c;
		}
	}else if(k==2){
		//set
		isSet[no] = true;
		sumw[no] = c*noCount[no];
		lazySet[no] = c;

		if(cyCount[no]){
			mx[no] = c;
			mxCount[no] = cyCount[no];
		}else{
			mx[no] = -INF;
			mxCount[no] = 0;
		}
	}
}

void doLazy(int no, int i, int j){
	if(i!=j){
		if(isSet[no]){
			makeLazy(no*2+1,2,lazySet[no]);
			makeLazy(no*2+2,2,lazySet[no]);
		}else if(lazyAdd[no]){
			makeLazy(no*2+1,1,lazyAdd[no]);
			makeLazy(no*2+2,1,lazyAdd[no]);
		}
		updateNode(no);
	}

	isSet[no] = false;
	lazyAdd[no] = 0;
	lazySet[no] = 0;
}

void updateSeg(int no, int i, int j, int x, int y, int k, int c){
	//k = 1 -> add , 2 -> set
	//printf("Call %d : %d %d\n",no,i,j);
	doLazy(no,i,j);
	if(x<=i&&j<=y){
		//sebseq
		makeLazy(no,k,c);
	}else if(isIntersect(i,j,x,y)){
		updateSeg(no*2+1,i,i+(j-i)/2,x,y,k,c);
		updateSeg(no*2+2,i+(j-i)/2+1,j,x,y,k,c);
		updateNode(no);
	}
	//printf("no %d : %d %d : %d %d %d : %d %d %d\n",no,i,j,sumw[no],mx[no],mxCount[no],isSet[no],lazySet[no],lazyAdd[no]);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d",&a,&b,&w);
		edge[a].push_back({b,w});
		edge[b].push_back({a,w});

		edgeList.push_back(Edge(a,b,w,i));
	}
	//find cycle
	findCycle(1,0);

	for(Edge& e : edgeList){
		if(isCy[e.a]&&isCy[e.b]){
			e.isCy = true;
		}
	}

	makeSeg(0, 0, n-1);

	for(int i = 0; i < q; i++){
		scanf("%d%d%d%d",&k,&s,&t,&c);
		s--,t--;
		updateSeg(0,0,n-1,s,t,k,c);
		printf("%d %d\n",sumw[0]-mx[0],mxCount[0]);
	} 

}