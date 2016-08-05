#include "stdio.h"
#include "vector"
#include "algorithm"
#include "stack"

struct quno{
	int ti,hi,id;
	quno(int _ti = 0, int _hi = 0, int _id = 0) : ti(_ti), hi(_hi), id(_id) {}
};

int n,m,a,b,co,gtime;
std::vector<int> edge[100005];
std::vector<std::pair<int,int> > qu[100005];
int h[100005];
int p[100005][20];
std::vector<int> child[100005];
bool isD[100005];
int hc[100005];
std::stack<quno> loopQu;

void rooting(int x, int o, int d){
	p[x][0] = o;
	h[x] = d;
	for(int i = 1; i <= 18; i++){
		p[x][i] = p[p[x][i-1]][i-1];
	}

	for(int i : edge[x]){
		if(i!=o){
			child[x].push_back(i);
			rooting(i,x,d+1);
		}
	}
}

int lca(int x, int y){
	//printf("LCA %d %d = ",x,y);
	if(h[x]>h[y]){
		for(int i = 18; i >= 0; i--){
			if(h[x]-h[y]>=(1<<i)){
				x = p[x][i];
			}
		}
	}else{
		for(int i = 18; i >= 0; i--){
			if(h[y]-h[x]>=(1<<i)){
				y = p[y][i];
			}
		}
	}

	for(int i = 18; i >= 0; i--){
		if(p[x][i]!=p[y][i]){
			x = p[x][i];
			y = p[y][i];
		}
	}
	//printf(" %d\n",x==y?x:p[x][0]);
	return x==y?x:p[x][0];
}

void solve(int x, int o){
	int nt = gtime++;
	//printf("solve %d %d\n",x,o);
	for(auto pi : qu[x]){
		int lc = lca(x,pi.first);
		loopQu.push(quno(nt,h[lc],pi.second));
		hc[h[lc]]++;
	}
	for(int ch : child[x]){
		solve(ch,x);
	}
	if(hc[h[x]]){
		co++;
		//printf("SET %d\n",x);
		while(!loopQu.empty()&&loopQu.top().ti>=nt){
			quno tmp = loopQu.top();
			if(!isD[tmp.id]){
				isD[tmp.id] = true;
				hc[tmp.hi] -= 2;
			}
			loopQu.pop();
		}
	}
	//printf("Size : %d\n",loopQu.size());
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i < n; i++){
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	rooting(1,0,1);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		qu[a].push_back({b,i});
		qu[b].push_back({a,i});
	}
	solve(1,0);
	printf("%d\n",co);
}